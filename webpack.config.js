const path = require("path");

module.exports = [
  {
    mode: "production",
    entry: "./app/assets/javascripts/application.js",
    output: {
      path: path.resolve(__dirname, "lib/"),
      filename: "application.js"
    }
  }
];

