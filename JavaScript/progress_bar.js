class ProgressBar {
  constructor(totalDelay = 10, length = 100) {
    if (length < 1) {
      throw new Error("Progress bar length must be greater than 0");
    }
    this.bar = Array(length).fill("-");
    this.index = 0;
    this.length = length;
    this.delay = (totalDelay * 1000) / length;
    this.isCompleted = false;
  }

  advance() {
    if (this.isCompleted) return;
    this.bar[this.index] = "#";
    this.index++;
    if (this.index >= this.length) {
      this.isCompleted = true;
    }
  }

  display() {
    process.stdout.write("\r" + this.bar.join(""));
  }

  start() {
    this.display();
    const intervalId = setInterval(() => {
      this.advance();
      this.display();
      if (this.isCompleted) {
        clearInterval(intervalId);
      }
    }, this.delay);
  }
}

const pb = new ProgressBar(10);
pb.start();
