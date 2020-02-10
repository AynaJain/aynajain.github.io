let fish;
let fish3;
let fishX;
let fishY;
let fishXS;
let fishYS;
let fish3X;
let fish3Y;
let fish3XS;
let fish3YS;
let bubbles = [];
let plant1;
let plant2;
let plant3;
let plant4;


function preload() {
  fish = loadImage("images/fish1.png");
  fish3 = loadImage("images/fish3.png");
  plant1 = loadImage("images/plant1.png");
  plant2 = loadImage("images/plant2.png");
  plant3 = loadImage("images/plant3.png");
  plant4 = loadImage("images/plant4.png");
}

function mousePressed()  {
  let r = random(10, 30);
  let b = new Bubble(mouseX, mouseY, r);
  bubbles.push(b);
}


function setup() {
  createCanvas(windowWidth, windowHeight);
  imageMode(CENTER);
  fishX = random(25, width-25);
  fishY = random(25, height-25);
  fish3X = random(50, width-50);
  fish3Y = random(50, height-50);
  fishXS = 1;
  fishYS = 1;
  fish3XS = 1;
  fish3YS = 1;

}

function draw() {
  background(116, 214, 242);
  image(plant1, 370, 620, 430, 400);
  image(plant2, 110, 490, 430, 680);
  image(plant3, 700, 620, 430, 500);
  image(plant1, 980, 620, 430, 400);
  image(plant4, 1310, 530, 430, 750);

  for (let i = 0; i < bubbles.length; i++)  {
    bubbles[i].move();
  }
  for (let j = 0; j < bubbles.length; j++)  {
    bubbles[j].show();
  }

  fishX = fishX + fishXS;
  fishY = fishY + fishYS;

  if(fishX >= width-25 || fishX <= 0){
    fishXS = fishXS * -1;
  }

  if(fishY >= height+80 || fishY <= 0){
    fishYS = fishYS * -1;
  }
  image(fish, fishX, fishY, 200, 200);

  fish3X = fish3X + fish3XS;
  fish3Y = fish3Y + fish3YS;

  if(fish3X >= width-25 || fish3X <= 0){
    fish3XS = fish3XS * -1;
  }

  if(fish3Y >= height+400 || fish3Y <= 0){
    fish3YS = fish3YS * -1;
  }
  image(fish3, fish3X, fish3Y, 250, 190);


  // for (let i = 0; i < 100; i++) {
  //   let r = random(50);
  //   stroke(r * 5);
  //   line(200, i, 50 + r, i);
  // }


}

class Bubble  {
  constructor(x, y, r)  {
    this.x = x;
    this.y = y;
    this.r = r;
  }
  move()  {
    this.x = this.x + random(-5, 5);
    this.y = this.y + random(-5, 5);
  }

  show()  {
    stroke(random(255), 0, random(100));
    strokeWeight(1);
    noFill();;
    ellipse(this.x, this.y, this.r*2,);
  }

}
