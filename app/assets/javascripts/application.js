import {
  createAudioPlayer,
  updateStickyAudioPlayer
} from "./audioPlayer.js";

window.Cms ||= {};

window.Cms.createAudioPlayer = function(audioPlayer, source) {
  createAudioPlayer(audioPlayer, source);
  document.addEventListener("scroll", function() {
    updateStickyAudioPlayer(audioPlayer);
  });
}
