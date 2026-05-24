// Minimal, clear logic
const $ = s => document.querySelector(s);
const toggleTheme = $('#toggleTheme');
const showInfo = $('#showInfo');
const rotate = $('#rotate');
const device = $('#device');
const message = $('#message');

toggleTheme?.addEventListener('click', () => {
  document.documentElement.classList.toggle('dark');
  toggleTheme.textContent = document.documentElement.classList.contains('dark') ? 'Tema: E errët' : 'Tema: E ndritshme';
});

showInfo?.addEventListener('click', () => {
  alert(message?.textContent.trim() ?? 'Pa mesazh');
});

rotate?.addEventListener('change', () => {
  if (!device) return;
  device.classList.toggle('landscape', rotate.checked);
  device.classList.toggle('portrait', !rotate.checked);
});
