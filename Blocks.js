let xc, yc, sc, vx, vy, size, temp, w, n, p
let blocksX = []
let blocksY = []
let blocksS = []
let blocksH = []

function setup() {
  createCanvas(600, 500);
  xc = width / 2
  yc = height / 2
  sc = 10
  vx = 0
  vy = 7
  size = 100
  w = 0
  n = 5
  p = 1
  for (i = 0; i < n; i++) {
    blocksH[i] = round(random(1, 3))
    blocksS[i] = round(random(20, 50))
    blocksX[i] = round(random(blocksS[i] / 2, width - blocksS[i] / 2))
    blocksY[i] = round(random(blocksS[i] / 2, height / 2 - blocksS[i]))
  }
  textAlign(CENTER, CENTER)
  textSize(72)
  draw()
  frameRate(0.4)
}

function draw() {
  if (p == 1) {
    frameRate(60)
    background(0);
    rectMode(CENTER)
    noStroke()
    for (let i = 0; i < blocksS.length; i++) {
      if (blocksH[i] != 0) {
        if (blocksH[i] == 1) {
            fill(150, 0, 0)
        } else if (blocksH[i] == 2) {
            fill(255, 255, 0)
        } else if (blocksH[i] == 3) {
            fill(0, 150, 0)
        }
        square(blocksX[i], blocksY[i], blocksS[i])
      }
    }
    fill(200, 200, 255)
    circle(xc, yc, 20)
    rect(mouseX, height - 20, size, sc)
    for (i = 0; i < blocksS.length; i++) {
      if (blocksH[i] == 0) {
        w++
      } else {
        w = 0
        break
      }
    }
    if (w == blocksS.length) {
      text("YOU WIN!", width / 2, height / 2)
      noLoop()
    }
    if ((yc >= height - 20 - sc) && (xc >= (mouseX - size / 2)) && (xc <= (mouseX + size / 2))) {
      temp = vx
      vx = sqrt(vx ** 2 + vy ** 2) * (sin(PI * (xc - mouseX) / size))
      vy = sqrt(temp ** 2 + vy ** 2) * (-cos(PI * (xc - mouseX) / size))
    }
    if ((xc <= sc) || (xc >= (width - sc))) {
      vx = -vx
    }
    if (yc <= sc) {
      vy = -vy
    }
    if (yc >= height) {
      text("YOU LOSE!", width / 2, height / 2)
      noLoop()
    }

    for (let i = 0; i < blocksS.length; i++) {
      if (blocksH[i] > 0) {
        if (((xc + sc) >= (blocksX[i] - blocksS[i] / 2)) && ((xc - sc) <= (blocksX[i] + blocksS[i] / 2)) && ((yc + sc) >= (blocksY[i]) - blocksS[i] / 2) && ((yc - sc) <= (blocksY[i] + blocksS[i] / 2))) {
          if (abs(xc - blocksX[i]) >= abs(yc - blocksY[i])) {
            vx = -vx
          }
          if (abs(xc - blocksX[i]) <= abs(yc - blocksY[i])) {
            vy = -vy
          }
          blocksH[i]--
        }
      }
    }
    xc += vx
    yc += vy
  }
}

function keyPressed() {
  p *= -1
}
