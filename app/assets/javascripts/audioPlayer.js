function getTimeCodeFromNum(num) {
  let seconds = parseInt(num);
  let minutes = parseInt(seconds / 60);
  seconds -= minutes * 60;
  const hours = parseInt(minutes / 60);
  minutes -= hours * 60;

  if (hours === 0) return `${minutes}:${String(seconds % 60).padStart(2, 0)}`;
  return `${String(hours).padStart(2, 0)}:${String(minutes).padStart(2, 0)}:${String(
    seconds % 60
  ).padStart(2, 0)}`;
}

function updateTime(element, value) {
  element.textContent = getTimeCodeFromNum(value);
}

function updateTimeLength(audioPlayer, value) {
  updateTime(audioPlayer.querySelector(".time .length"), value);
}

function updateTimeCurrent(audioPlayer, audio) {
  const progressBar = audioPlayer.querySelector(".progress");
  progressBar.style.width = audio.currentTime / audio.duration * 100 + "%";
  updateTime(audioPlayer.querySelector(".time .current"), audio.currentTime);
}

function onLoadedData(audioPlayer, audio) {
  updateTimeLength(audioPlayer, audio.duration);
  audio.volume = 0.75;
}

function onPlayClicked(audio, button) {
  if (audio.paused) {
    button.classList.remove("play");
    button.classList.add("pause");
    audio.play();
  } else {
    button.classList.remove("pause");
    button.classList.add("play");
    audio.pause();
  }
}

function onVolumeButtonClicked(audioPlayer, audio) {
  const container = audioPlayer.querySelector(".volume-container");
  audio.muted = !audio.muted;
  container.classList[audio.muted ? 'add' : 'remove']("nute");
}

export function createAudioPlayer(audioPlayer, source) {
  const audio = new Audio(source);
  const timeline = audioPlayer.querySelector(".timeline");
  const volumeSlider = audioPlayer.querySelector(".controls .volume-slider");
  const playButton = audioPlayer.querySelector(".controls .toggle-play");
  const volumeButton = audioPlayer.querySelector(".volume-button");

  audio.addEventListener(
    "loadeddata", onLoadedData.bind(this, audioPlayer, audio), false
  );
  playButton.addEventListener(
    "click", onPlayClicked.bind(this, audio, playButton), false
  );
  volumeButton.addEventListener(
    "click", onVolumeButtonClicked.bind(this, audioPlayer)
  );
  timeline.addEventListener("click", function(event) {
    const timelineWidth = window.getComputedStyle(timeline).width;
    const timeToSeek = event.offsetX / parseInt(timelineWidth) * audio.duration;
    console.log("clicked on timeline; new time=", timeToSeek);
    audio.currentTime = timeToSeek;
    updateTimeCurrent(audioPlayer, audio);
  }, false);
  volumeSlider.addEventListener("click", function(event) {
    const sliderWidth = window.getComputedStyle(volumeSlider).width;
    const newVolume = event.offsetX / parseInt(sliderWidth);
    console.log("clicked on volume slider; new volume=", newVolume);
    audio.volume = newVolume;
    audioPlayer.querySelector(".controls .volume-percentage").style.width = newVolume * 100 + '%';
  }, false)
  setInterval(updateTimeCurrent.bind(this, audioPlayer, audio), 1000);
}

export function updateStickyAudioPlayer(audioPlayer) {
  const player = audioPlayer.parentElement;
  const offset = player.offsetTop + player.offsetHeight - 48;
  const method = window.scrollY >= offset ? "add" : "remove";

  player.classList[method]("stick");
}
