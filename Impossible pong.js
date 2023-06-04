let xc, yc, sc, vx, vy, size, temp, spd, pts1, pts2, pts, p
let scores = []

function setup() {
  createCanvas(400, 400);
  pts = 7
  xc = width / 2
  yc = height / 2
  sc = 10
  spd = 1.001
  vx = 0
  vy = 5
  size = 100
  pts1 = 0
  pts2 = 0
  p = 1
  draw()
  frameRate(0.4)
}

function draw() {
  if (p == 1) {
    frameRate(60)
    background(0);
    textAlign(CENTER, CENTER)
    textSize(72)
    fill(0, 255, 0, 50)
    text("PONG", width / 2, height / 4)
    text("By: Vardhan", width / 2, 3 * height / 4)
    textAlign(LEFT, CENTER)
    textSize(20)
    fill(255, 255, 0)
    text(pts1, 1, height / 2 + 20)
    text(pts2, 1, height / 2 - 15)
    for (i = 0; i < scores.length; i++) {
      text(scores[i], 1, 16 * (i + 1) + 1)
    }
    text(round(sqrt(vx ** 2 + vy ** 2), 3), 1, 16 * (scores.length + 1) + 1)
    textAlign(CENTER, CENTER)
    textSize(72)
    rectMode(CENTER)
    stroke(255)
    strokeWeight(5)
    noFill()
    circle(width / 2, height / 2, 50)
    circle(width / 2, height / 2, 5)
    line(0, height / 2, width / 2 - 25, height / 2)
    line(width / 2 + 25, height / 2, width, height / 2)
    noStroke()

    fill(200, 200, 255)
    circle(xc, yc, 20)
    rect(mouseX, height - 20, size, sc)
    rect(xc, 20, size, sc)
    if ((yc >= height - 20 - sc) && (xc >= (mouseX - size / 2)) && (xc <= (mouseX + size / 2))) {
      temp = vx
      vx = sqrt(vx ** 2 + vy ** 2) * (sin(PI * (xc - mouseX) / size))
      vy = sqrt(temp ** 2 + vy ** 2) * (-cos(PI * (xc - mouseX) / size))
    }
    if (yc <= 20 + sc) {
      vy = -vy
    }
    if ((xc <= sc) || (xc >= (width - sc))) {
      vx = -vx
    }
    if (yc <= sc) {
      pts1++
      scores.push(round(sqrt(vx ** 2 + vy ** 2), 3))
      xc = width / 2
      yc = height / 2
      vx = 0
      vy = -5
    }
    if (yc >= height) {
      pts2++
      scores.push(round(sqrt(vx ** 2 + vy ** 2), 3))
      xc = width / 2
      yc = height / 2
      vx = 0
      vy = 5
    }
    if (pts1 >= pts) {
      text("YOU WIN!", width / 2, height / 2)
      noLoop()
    }
    if (pts2 >= pts) {
      text("YOU LOSE!", width / 2, height / 2)
      noLoop()
    }
    xc += vx
    yc += vy
    vx *= spd
    vy *= spd
  }
}

function keyPressed() {
  p *= -1
}
