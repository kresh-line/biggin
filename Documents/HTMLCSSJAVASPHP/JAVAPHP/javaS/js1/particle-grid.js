const canvas = document.getElementById("particle-grid");
const ctx = canvas.getContext("2d");
const ptr = { x: 0, y: 0, active: false, radius: 240 };
let segments = [], gap = 36, segLen = 26, lw = 1.15, dpr = 1, tick = 0;

function resizeCanvas() {
    const { innerWidth: w, innerHeight: h } = window;
    const sm = w < 640;
    dpr = Math.min(window.devicePixelRatio || 1, 2);
    canvas.width = w * dpr; canvas.height = h * dpr;
    canvas.style.width = w + "px"; canvas.style.height = h + "px";
    ctx.setTransform(dpr, 0, 0, dpr, 0, 0);
    gap = sm ? 30 : 36; segLen = sm ? 18 : 26; lw = sm ? 1 : 1.15; ptr.radius = sm ? 180 : 240;

    segments = [];
    const ox = (w % gap) / 2, oy = (h % gap) / 2;
    let row = 0;
    for (let y = oy; y < h; y += gap, row++) {
        let col = 0;
        for (let x = ox; x < w; x += gap, col++) {
            segments.push({
                baseX: x, baseY: y, x, y, offsetX: 0, offsetY: 0, tilt: 0,
                phase: Math.random() * Math.PI * 2,
                drift: 0.65 + Math.random() * 1.35,
                chaos: Math.random() * 2 - 1,
                orientation: (row + col) % 2 === 0 ? "h" : "v"
            });
        }
    }
}

function frame() {
    tick += 0.018;
    ctx.clearRect(0, 0, canvas.width, canvas.height);

    for (const s of segments) {
        const dx = ptr.x - s.baseX, dy = ptr.y - s.baseY;
        const dist = Math.hypot(dx, dy) || 0.001;
        const wx = Math.sin(tick * s.drift + s.phase) * 1.8;
        const wy = Math.cos(tick * s.drift * 0.9 + s.phase) * 1.8;
        const wt = Math.sin(tick * s.drift * 0.7 + s.phase) * 0.08;
        let tx = wx, ty = wy, tt = wt, alpha = 0.34, ls = 1;

        if (ptr.active && dist < ptr.radius) {
            const force = (1 - dist / ptr.radius) ** 1.8;
            const angle = Math.atan2(dy, dx);
            const swirl = Math.sin(tick * 2.2 + s.phase + dist * 0.03);
            const push = force * (26 + Math.abs(s.chaos) * 18);
            tx = -Math.cos(angle) * push + (-Math.sin(angle)) * force * 20 * s.chaos + wx * (1 + force * 2.2) + swirl * 10;
            ty = -Math.sin(angle) * push + Math.cos(angle)  * force * 20 * s.chaos + wy * (1 + force * 2.2) - swirl * 10;
            tt = (s.orientation === "h" ? -1 : 1) * force * 0.55 + s.chaos * force * 0.45 + wt;
            alpha = 0.34 + force * 0.56; ls = 1 + force * 0.32;
        }

        s.offsetX += (tx - s.offsetX) * 0.12;
        s.offsetY += (ty - s.offsetY) * 0.12;
        s.tilt    += (tt - s.tilt)    * 0.12;
        s.x = s.baseX + s.offsetX;
        s.y = s.baseY + s.offsetY;

        const hl = segLen * ls / 2;
        const [sx, sy, ex, ey] = s.orientation === "h" ? [-hl, 0, hl, 0] : [0, -hl, 0, hl];
        ctx.save();
        ctx.translate(s.x, s.y);
        ctx.rotate(s.tilt);
        ctx.beginPath();
        ctx.moveTo(sx, sy);
        ctx.lineTo(ex, ey);
        ctx.lineWidth = lw;
        ctx.lineCap = "round";
        ctx.strokeStyle = `rgba(214,219,235,${alpha})`;
        ctx.stroke();
        ctx.restore();
    }

    requestAnimationFrame(frame);
}

const setPtr = (x, y) => { ptr.x = x; ptr.y = y; ptr.active = true; };
canvas.addEventListener("mousemove",  e => setPtr(e.clientX, e.clientY));
canvas.addEventListener("mouseenter", e => setPtr(e.clientX, e.clientY));
canvas.addEventListener("mouseleave", () => ptr.active = false);
["touchstart", "touchmove"].forEach(t =>
    canvas.addEventListener(t, e => { const p = e.touches[0]; if (p) setPtr(p.clientX, p.clientY); }, { passive: true })
);
canvas.addEventListener("touchend", () => ptr.active = false, { passive: true });
window.addEventListener("resize", resizeCanvas);

resizeCanvas();
frame();
