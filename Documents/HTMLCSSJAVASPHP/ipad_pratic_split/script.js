(() => {
  const rig = document.getElementById('rig');
  const stage = document.getElementById('stage');
  const ipadEl = document.getElementById('ipad');
  const armL = document.getElementById('arm-l');
  const armR = document.getElementById('arm-r');
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

  function updateHinge() {
    // Screen: 0° = upright, positive = tilt backward, negative = tilt forward
    const hinge = +screenSlider.value;
    screenVal.textContent = hinge + '°';
    ipadEl.style.transform = `translate(-50%, -50%) rotateX(${-hinge}deg)`;

    // Arm: 90° = vertical, 0° = forward, 180° = backward
    const tilt = +armSlider.value;
    armVal.textContent = tilt + '°';
    const armRot = 90 - tilt;
    armL.style.transform = `rotateX(${armRot}deg)`;
    armR.style.transform = `rotateX(${armRot}deg)`;
    pivotAnchor.style.transform = `translateX(-50%) rotateX(${armRot}deg)`;
  }

  screenSlider.addEventListener('input', updateHinge);
  armSlider.addEventListener('input', updateHinge);
  updateHinge();

  applyRig();
})();
