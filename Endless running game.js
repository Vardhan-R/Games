let pts, spd, y, vy, g, t, temp, x, xoff
let b = []
let xb = []
let xstars = []
let ystars = []

function setup() {
  createCanvas(400, 400);
  pts = 0
  spd = 1
  x = 0
  g = 0
  temp = 0
  xoff = 0.005
  vy = 0
  y = height / 2 - 10
  t = 0.02
  textSize(20)
  for (let i = 0; i < 100; i++) {
    xstars[i] = round(random(0, width))
    ystars[i] = round(random(0, height / 3))
  }
}



function draw() {
  background(0);
  if (pts % round((200 / spd)) == 0) {
    b[b.length] = round(random(1, 3))
    xb[xb.length] = width + 100
  }
  for (let i = 0; i < xb.length; i++) {
    xb[i] -= spd
  }

  strokeWeight(1)
  stroke(255)
  for (i = 0; i < 100; i++) {
    point(xstars[i], ystars[i])
  }
  line(0, height / 2, width, height / 2)
  noStroke()
  fill(255, 255, 0)
  text(pts, 1, 20)
  if (vy != 0 && y > height / 2 - 11) {
    g = 300
  }
  if (y > height / 2 - 10) {
    vy = 0
    g = 0
    y = height / 2 - 10
  }
  fill(255, 255, 200)
  circle(width - 50, 50, 25)
  fill(0)
  circle(width - 59, 43, 30)
  fill(255 * noise(x), 255 * noise(x + 5000), 255 * noise(x + 10000))
  rectMode(CENTER)
  square(20, y, 20)
  rectMode(CORNER)
  temp = vy
  vy += g * t
  if (g != 0) {
    y += (vy ** 2 - temp ** 2) / (2 * g)
  }
  pts += 1
  x += xoff
  spd += 0.001

  fill(255)
  for (let i = 0; i < xb.length; i++) {
    rect(xb[i], height / 2 - 30, 10 * b[i], 30)
  }

  for (let i = 0; i < b.length; i++) {
    if ((xb[i] < 30) && ((xb[i] + 10 * b[i]) > 10) && ((y + 10) > height / 2 - 30)) {
      noLoop()
    }
  }
  for (let i = 0; i < xstars.length; i++) {
    xstars[i] -= 1
    if (xstars[i] < 0) {
      xstars[i] += width
    }
  }
  noStroke()
  fill(48, 24, 0)
  rect(0, height / 2, width, height / 2)
}

function keyPressed() {
  // console.log(y)
  if (keyCode === UP_ARROW || keyCode === 32) {
    if (y == height / 2 - 10) {
      vy = -200
    }
  } else if (keyCode === DOWN_ARROW) {
    y = height / 2 - 10
    vy = 0
  }
}
