const canvas = document.getElementById("particle-grid");
const context = canvas.getContext("2d");

const pointer = {
    x: 0,
    y: 0,
    active: false,
    radius: 240
};

let segments = [];
let gap = 28;
let segmentLength = 26;
let lineWidth = 1.15;
let dpr = Math.min(window.devicePixelRatio || 1, 2);
let tick = 0;

function resizeCanvas() {
    const { innerWidth, innerHeight } = window;

    dpr = Math.min(window.devicePixelRatio || 1, 2);
    canvas.width = innerWidth * dpr;
    canvas.height = innerHeight * dpr;
    canvas.style.width = innerWidth + "px";
    canvas.style.height = innerHeight + "px";
    context.setTransform(dpr, 0, 0, dpr, 0, 0);

    gap = innerWidth < 640 ? 30 : 36;
    segmentLength = innerWidth < 640 ? 18 : 26;
    lineWidth = innerWidth < 640 ? 1 : 1.15;
    pointer.radius = innerWidth < 640 ? 180 : 240;

    buildGrid(innerWidth, innerHeight);
}

function buildGrid(width, height) {
    segments = [];

    const offsetX = (width % gap) / 2;
    const offsetY = (height % gap) / 2;
    let row = 0;

    for (let y = offsetY; y < height; y += gap) {
        let column = 0;
        for (let x = offsetX; x < width; x += gap) {
            segments.push({
                baseX: x,
                baseY: y,
                x,
                y,
                offsetX: 0,
                offsetY: 0,
                tilt: 0,
                phase: Math.random() * Math.PI * 2,
                drift: 0.65 + Math.random() * 1.35,
                chaos: Math.random() * 2 - 1,
                orientation: (row + column) % 2 === 0 ? "horizontal" : "vertical"
            });
            column += 1;
        }
        row += 1;
    }
}

function drawSegment(segment, alpha, lengthScale) {
    const halfLength = (segmentLength * lengthScale) / 2;
    let startX;
    let startY;
    let endX;
    let endY;

    if (segment.orientation === "horizontal") {
        startX = -halfLength;
        startY = 0;
        endX = halfLength;
        endY = 0;
    } else {
        startX = 0;
        startY = -halfLength;
        endX = 0;
        endY = halfLength;
    }

    context.save();
    context.translate(segment.x, segment.y);
    context.rotate(segment.tilt);
    context.beginPath();
    context.moveTo(startX, startY);
    context.lineTo(endX, endY);
    context.lineWidth = lineWidth;
    context.lineCap = "round";
    context.strokeStyle = `rgba(214, 219, 235, ${alpha})`;
    context.stroke();
    context.restore();
}

function updateSegments() {
    tick += 0.018;
    context.clearRect(0, 0, canvas.width, canvas.height);

    for (const segment of segments) {
        const dx = pointer.x - segment.baseX;
        const dy = pointer.y - segment.baseY;
        const distance = Math.hypot(dx, dy) || 0.001;
        const withinRange = pointer.active && distance < pointer.radius;

        let targetOffsetX = 0;
        let targetOffsetY = 0;
        let targetTilt = 0;
        let alpha = 0.34;
        let lengthScale = 1;
        const idleWaveX = Math.sin(tick * segment.drift + segment.phase) * 1.8;
        const idleWaveY = Math.cos(tick * (segment.drift * 0.9) + segment.phase) * 1.8;
        const idleTilt = Math.sin(tick * (segment.drift * 0.7) + segment.phase) * 0.08;

        if (withinRange) {
            const force = (1 - distance / pointer.radius) ** 1.8;
            const angle = Math.atan2(dy, dx);
            const swirl = Math.sin(tick * 2.2 + segment.phase + distance * 0.03);
            const tangentX = -Math.sin(angle);
            const tangentY = Math.cos(angle);
            const push = force * (26 + Math.abs(segment.chaos) * 18);

            targetOffsetX = -Math.cos(angle) * push + tangentX * force * 20 * segment.chaos + idleWaveX * (1 + force * 2.2) + swirl * 10;
            targetOffsetY = -Math.sin(angle) * push + tangentY * force * 20 * segment.chaos + idleWaveY * (1 + force * 2.2) - swirl * 10;
            targetTilt = (segment.orientation === "horizontal" ? -1 : 1) * force * 0.55 + segment.chaos * force * 0.45 + idleTilt;
            alpha = 0.34 + force * 0.56;
            lengthScale = 1 + force * 0.32;
        } else {
            targetOffsetX = idleWaveX;
            targetOffsetY = idleWaveY;
            targetTilt = idleTilt;
        }

        segment.offsetX += (targetOffsetX - segment.offsetX) * 0.12;
        segment.offsetY += (targetOffsetY - segment.offsetY) * 0.12;
        segment.tilt += (targetTilt - segment.tilt) * 0.12;
        segment.x = segment.baseX + segment.offsetX;
        segment.y = segment.baseY + segment.offsetY;

        drawSegment(segment, alpha, lengthScale);
    }

    window.requestAnimationFrame(updateSegments);
}

function setPointerPosition(clientX, clientY) {
    pointer.x = clientX;
    pointer.y = clientY;
    pointer.active = true;
}

canvas.addEventListener("mousemove", (event) => {
    setPointerPosition(event.clientX, event.clientY);
});

canvas.addEventListener("mouseenter", (event) => {
    setPointerPosition(event.clientX, event.clientY);
});

canvas.addEventListener("mouseleave", () => {
    pointer.active = false;
});

canvas.addEventListener("touchstart", (event) => {
    const touch = event.touches[0];
    if (touch) {
        setPointerPosition(touch.clientX, touch.clientY);
    }
}, { passive: true });

canvas.addEventListener("touchmove", (event) => {
    const touch = event.touches[0];
    if (touch) {
        setPointerPosition(touch.clientX, touch.clientY);
    }
}, { passive: true });

canvas.addEventListener("touchend", () => {
    pointer.active = false;
}, { passive: true });

window.addEventListener("resize", resizeCanvas);

resizeCanvas();
updateSegments();
