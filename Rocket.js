let angle, maxVel

function setup() {
  createCanvas(400, 400);
  p = createVector(width / 2, height / 2)
  v = createVector(0, 0)
  a = createVector(0, 0)
  angle = 0
  maxVel = 2
  rectMode(CENTER)
}



function draw() {
  background(0);
  grid(10, 10, 255, 20)
  push()
  translate(p.x, p.y)
  rotate(angle)
  v.add(a)
  v.limit(maxVel)
  p.add(v)
  pop()
  stroke(255, 0, 0)
  fill(0, 255, 0, 50)
  pos = createVector(p.x - width / 2, p.y - height / 2)
  if (width < height) {
    pos.limit(width / 2)
    circle(width / 2, height / 2, width)
  } else {
    pos.limit(height / 2)
    circle(width / 2, height / 2, height)
  }
  p = createVector(pos.x + width / 2, pos.y + height / 2)
  noStroke()
  fill(255)
  push()
  translate(p.x, p.y)
  rotate(angle)
  triangle(0, 0, -20, 5, -20, -5)
  rect(-20, 3, 4, 3)
  rect(-20, -3, 4, 3)

  if (keyIsDown(32)) {
    a = (0, 1)
    a = p5.Vector.fromAngle(angle)
    fill(255, 100, 0)
    triangle(-21, 4, -25, 3, -21, 2)
    triangle(-21, -4, -25, -3, -21, -2)
  } else {
    a = (0, 0)
  }

  if (keyIsDown(LEFT_ARROW)) {
    angle -= PI / 100
  } else if (keyIsDown(RIGHT_ARROW)) {
    angle += PI / 100
  }

  v.mult(0.99)
  if (mag(v.x, v.y) < 0.1) {
    v.setMag(0)
  }
  pop()
}

function grid (r, c, colour, alp) {
  strokeWeight(1)
  stroke(colour, alp)
  for (i = 1; i < r; i++) {
    line(0, i * height / r, width, i * height / r)
  }
  for (i = 1; i < c; i++) {
    line(i * width / c, 0, i * width / c, height)
  }
}
