// let yoff = 0.0; // 2nd dimension of perlin noise
// let car;
// let car1;
// let monster;
// let monst;
// // let gameOver;
// let bull;
// let bulletImage;
// let bulletMoving = false;
// let bulletX;
// let bulletY = 500;
// let score=0;
//
// function preload(){
//   car = loadImage('images/car4.jpg');
//   car1 = loadImage('images/back1.jpg');
//   monster = loadImage('images/monster.png');
//   bulletImage = loadImage('images/bullet.png');
// }
//
// function setup() {
//   createCanvas(windowWidth, windowHeight);
//   bulletX = 500;
//
//   // bull = new Group();
//   // monst = new Group();
//   // gameOver = true;
//   // updateSprites(false);
//
//   // monster = createSprite(width/2, 0, 10,30);
// }
//
// function draw() {
//   // car1.filter(BLUR, 10);
// background(car1);
//
//   fill(255);
//   // We are going to draw a polygon out of the wave points
//   beginShape();
//
//   let xoff = 0; // Option #1: 2D Noise
//   // let xoff = yoff; // Option #2: 1D Noise
//   let y;
//   let y1;
//   let carX = [];
//   let monsterX = [];
//   // Iterate over horizontal pixels
//   for (let x = 0; x <= width; x += 10) {
//     // Calculate a y value according to noise, map to
//     // Option #1: 2D Noise
//     y = map(noise(xoff, yoff), 0, 1, 550, 750);
//
//     carX.push(y);
//     monsterX.push(y);
//
//     // Option #2: 1D Noise
//     // let y = map(noise(xoff), 0, 1, 200,300);
//     // image(car, x, y-50, 50, 50);
//     // Set the vertex
//     vertex(x, y);
//     // noStroke();
//     // stroke(0);
//     // vertex(x, y1);
//     // Increment x dimension for noise
//     xoff += 0.05;
//     // carX += 2;
//     }
//     // let i = (width/10);
//     image(car, 150, carX[400/10]-190, 400, 200);
//     image(monster, 1030, monsterX[400/10]-350, 300, 400);
//
//
//   // increment y dimension for noise
//     yoff += 0.01;
//     vertex(width, height);
//     vertex(0, height);
//     endShape(CLOSE);
//
//     if(bulletMoving === true){
//         image(bulletImage, bulletX, bulletY, 50, 50);
//         bulletX = bulletX + 50;
//         // checkCollision();
//         if(dist(1030,monsterX[400/10]-350,bulletX,bulletY) === 0)
//           {
//             bulletImage.hide()
//             monster.hide();
//             bulletMoving = false;
//             // print("hit");
//           }// else {
//
//
//     }
//
//     // monster.position.x = monster.position.x + 1;
//     // if(monster.position.x==car.position.x){
//     //   GameOver();
//     //   monster.position.x = random(5, width -5);
//     // }
//
//     // if(monster.overlap(car)){
//     //   gameOver();
//     // }
//     // if(bull.overlap(monster)){
//     //   // gameOver();
//     //   killMonster();
//     //   score++;
//     // }
//
//     // if(bulletMoving === true){
//     //   for(let i = 0; i < 20; i++){
//     //
//     //   }
//     // }
//
//     // if(gameOver && )
//     //   newGame();
//     // //
//     // if(!gameOver) {
//     //   if(bird.overlap(monster))
//     //     die();
//     //
//     //   if(frameCount % 60 = 0){
//     //     monst.addImage(monster);
//     //     image(monster, 250, monsterX[400/10]-200, 500, 200);
//     //   }
//
//     // if(keyWentDown('x'))
//     // {
//     //   var bullet = createSprite(car.position.x, car.position.y);
//     //   bullet.addImage(bulletImage);
//     //   bullet.setSpeed(10+car.getSpeed(), car.rotation);
//     //   bullet.life = 30;
//     //   bull.add(bullet);
//     // }
//
//   }
//
//   // function checkCollision(){
//   //   if(dist(1030,monsterX[400/10]-350,bulletX,bulletY)  10)
//   //   {
//   //     // bulletImage.hide();
//   //     print("hit");
//   //   }// else {
//   //   //   continue;
//   //   // }
//   // }
//
//   function keyTyped(){
//     if(key === 'f'){
//       bulletMoving = true;
//       // bulletX = 500;
//     }
//     if(key === 'r'){
//       bulletMoving = false;
//     }
//   }
//
//   // function gameOver() {
//   //   background(0)
//   //   textAlign(CENTER)
//   //   fill('white')
//   //   text('Game Over!', width / 2, height / 2)
//   //
//   //
//   //   function mouseClicked() {
//   //     if (gameOver) {
//   //       gameOver = false
//   //       // player.position.x = width / 2
//   //       // player.position.y = height - 25
//   //       monster.position.x = width / 2
//   //       monster.position.y = 0
//   //     }
//   //   }
//   // }


let isGameOver;
let player;
let playerImage;
let enemy;
let enemyImage;
let backgroundImage;
let score = 0;
let playss=0;

function preload() {
  playerImage = loadImage("images/11monster.png");
  enemyImage = loadImage("images/small_bullet.png");
  backgroundImage = loadImage("images/car1.jpg");
}

function setup() {
  isGameOver = false;
  createCanvas(400, 400);
  player = createSprite(width , height - (playerImage.height / 2), 0, 0);
  player.addImage(playerImage);
  enemy = createSprite(width / 2, 0, 0, 0);
  enemy.addImage(enemyImage);
  enemy.rotationSpeed = 2.0;

}

function draw() {
  if (isGameOver) {
    gameOver();
  } else {
    if (enemy.overlap(player)) {
      isGameOver = true;
    }
    background(backgroundImage);
    if (keyDown(RIGHT_ARROW) && player.position.x < (width - (playerImage.width / 2))) {
      player.position.x += 5;
    }
    if (keyDown(LEFT_ARROW) && player.position.x > (playerImage.width / 2)) {
      player.position.x -= 5;
    }
    enemy.position.y = enemy.position.y + 6;
    if (enemy.position.y > height) {
      enemy.position.y = 0;
      enemy.position.x = random(5, width - 5);
      score++;
    }
    drawSprites();
  }
}

// function Collision(){
//   playerImage.resize(20,30);
//   isGameOver=true;
// }

function gameOver() {
    background(232, 239, 16);
    textAlign(CENTER);
    fill("black");
    text("Game Over!", width / 2, height / 2);
    text("Score: ",width / 2, height / 2+20);
    text(score, width/2,height/2+40);
    text("Click anywhere to try again", width / 2, 3 * height / 4);
    isGameOver = true;

}

function mouseClicked() {
  isGameOver = false;
  score=0;
  player.position.x = width / 2;
  player.position.y = height - (playerImage.height / 2);
  enemy.position.x = width / 2;
  enemy.position.y = 0;
}
