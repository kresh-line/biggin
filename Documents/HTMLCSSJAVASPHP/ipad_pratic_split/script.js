(() => {
  const rig = document.getElementById('rig');
  const stage = document.getElementById('stage');
  const ipadEl = document.getElementById('ipad');
  const pivotAnchor = document.getElementById('pivot-anchor');

  let rx = -12, ry = -22;
  let dragging = false, lastX = 0, lastY = 0;
  let spinning = false;

  function applyRig() {
    if (spinning) return;
    rig.style.transform = `rotateX(${rx}deg) rotateY(${ry}deg)`;
  }

  function setView(name) {
    stopSpin();
    if (name === 'front') { rx = 0;   ry = 0;   }
    if (name === 'iso')   { rx = -12; ry = -22; }
    if (name === 'side')  { rx = 0;   ry = -85; }
    applyRig();
  }

  function startSpin() {
    spinning = true;
    rig.classList.add('spin');
    document.getElementById('btn-spin').setAttribute('aria-pressed', 'true');
  }
  function stopSpin() {
    if (!spinning) return;
    spinning = false;
    rig.classList.remove('spin');
    applyRig();
    document.getElementById('btn-spin').setAttribute('aria-pressed', 'false');
  }

  // Drag to rotate
  stage.addEventListener('pointerdown', (e) => {
    if (e.target.closest('input, button, .slider-wrap')) return;
    stopSpin();
    dragging = true;
    lastX = e.clientX; lastY = e.clientY;
    stage.setPointerCapture(e.pointerId);
    rig.style.transition = 'none';
  });
  stage.addEventListener('pointermove', (e) => {
    if (!dragging) return;
    ry += (e.clientX - lastX) * 0.5;
    rx -= (e.clientY - lastY) * 0.5;
    rx = Math.max(-60, Math.min(40, rx));
    lastX = e.clientX; lastY = e.clientY;
    applyRig();
  });
  stage.addEventListener('pointerup', () => { dragging = false; rig.style.transition = ''; });
  stage.addEventListener('pointercancel', () => { dragging = false; rig.style.transition = ''; });

  // Keyboard arrow + space
  window.addEventListener('keydown', (e) => {
    if (e.key === 'ArrowLeft')  { stopSpin(); ry -= 12; applyRig(); }
    if (e.key === 'ArrowRight') { stopSpin(); ry += 12; applyRig(); }
    if (e.key === 'ArrowUp')    { stopSpin(); rx -= 8;  rx = Math.max(-60, rx); applyRig(); }
    if (e.key === 'ArrowDown')  { stopSpin(); rx += 8;  rx = Math.min(40, rx);  applyRig(); }
    if (e.code === 'Space')     { e.preventDefault(); spinning ? stopSpin() : startSpin(); }
  });

  document.getElementById('btn-spin').onclick  = () => spinning ? stopSpin() : startSpin();
  document.getElementById('btn-front').onclick = () => setView('front');
  document.getElementById('btn-iso').onclick   = () => setView('iso');
  document.getElementById('btn-side').onclick  = () => setView('side');

  // Hinge controls
  const screenSlider = document.getElementById('screen-angle');
  const screenVal    = document.getElementById('screen-val');
  const armSlider    = document.getElementById('arm-angle');
  const armVal       = document.getElementById('arm-val');

  // --- Keyboard collision: the iPad cannot rotate through the keyboard plane. ---
  // Geometry: pivot at y=470 in rig. iPad center sits on that pivot when the arm
  // is rolled (anchor's transform-origin is 180px below itself, so y=470).
  // For the iPad's top/bottom edge midpoints (±180 in iPad local Y), the rig-Y after
  // combined rotations works out to:
  //   yBottom = 470 + 180 * (cos(h-ar) - cos(ar))
  //   yTop    = 470 - 180 * (cos(h-ar) + cos(ar))
  // h = screen tilt in deg, ar = arm rotation in deg.
  // Either dipping below 470 means the iPad is intersecting the keyboard surface.
  const KEY_Y = 470;
  function maxRigY(h, ar) {
    const hr = h  * Math.PI / 180;
    const ar2 = ar * Math.PI / 180;
    const cosD  = Math.cos(hr - ar2);
    const cosAr = Math.cos(ar2);
    const yBottom =  180 * (cosD - cosAr);
    const yTop    = -180 * (cosD + cosAr);
    return KEY_Y + Math.max(yBottom, yTop);
  }
  function isOk(h, ar) { return maxRigY(h, ar) <= KEY_Y + 0.5; }

  // Bisect to find the value closest to `raw` (in the same direction from `neutral`)
  // that satisfies isOk. Used to clamp whichever slider the user is dragging.
  function clampToward(raw, neutral, check) {
    if (check(raw)) return raw;
    let safe = neutral, unsafe = raw;
    for (let i = 0; i < 24; i++) {
      const mid = (safe + unsafe) / 2;
      if (check(mid)) safe = mid; else unsafe = mid;
    }
    return safe;
  }

  let lastSource = null;
  screenSlider.addEventListener('input', () => { lastSource = 'screen'; updateHinge(); });
  armSlider.addEventListener('input',    () => { lastSource = 'arm';    updateHinge(); });

  function updateHinge() {
    let hinge = +screenSlider.value;
    let tilt  = +armSlider.value;
    let armRot = 90 - tilt;

    if (!isOk(hinge, armRot)) {
      if (lastSource === 'arm') {
        // User is moving the arm — clamp tilt back toward 90 (vertical / neutral)
        tilt = clampToward(tilt, 90, t => isOk(hinge, 90 - t));
        armRot = 90 - tilt;
        armSlider.value = tilt;
      } else {
        // Default: clamp the screen hinge back toward 0 (upright)
        hinge = clampToward(hinge, 0, h => isOk(h, armRot));
        screenSlider.value = hinge;
      }
    }

    // Screen: 0° = upright, positive = tilt backward, negative = tilt forward
    screenVal.textContent = Math.round(hinge) + '°';
    ipadEl.style.transform = `translate(-50%, -50%) rotateX(${-hinge}deg)`;

    // Arm: 90° = vertical, 0° = forward, 180° = backward.
    // Arms live inside pivot-anchor, so they inherit this rotation automatically
    // and always stay locked behind the iPad in the same 3D plane.
    armVal.textContent = Math.round(tilt) + '°';
    pivotAnchor.style.transform = `translateX(-50%) rotateX(${armRot}deg)`;

    // Closed detection: when the screen's face is roughly parallel to the keyboard
    // (folded down onto / over it), turn the screen "off".
    const faceAngle = armRot + (-hinge);
    ipadEl.classList.toggle('closed', Math.abs(faceAngle) >= 70);
  }

  updateHinge();

  applyRig();
})();
