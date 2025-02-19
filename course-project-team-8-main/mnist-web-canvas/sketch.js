
let paint = false
let clear_button
let strokes = []
let prediction = ""
const scale = 25
let c, res = {};
let fil;
function getting(fil) {
  return fil;
}
function preload() {
  img = loadImage("uploads/predict.png");
}
function setup(){
 c = createCanvas(28 * scale, 28 * scale)
 image = (img, 0, 0, width, height);
   //img.resize(28,28);
  updatePixels();
  background(img)
  createDiv("</br>")
  clear_button = createButton("Clear")
  clear_button.mousePressed( () => strokes = [] )
}


function draw(){
  background(img)
  if(paint) strokes[strokes.length -1].paint(mouseX, mouseY)
  for(let stroke of strokes) stroke.draw(50, color(255))

  //if(strokes.length >= 0){
   // let img = img;
    loadPixels()
    //img.copy(c,0,0,width,height,0,0,width,height)
    img.loadPixels()
    //img.pixels = pixels2BinaryColor(img.pixels, 51)
    //img.updatePixels()
    img.resize(28, 28)
    let scaled_pixels = pixels2BW_arr(img.pixels, norm=true)
    httpGet("/predict?img=" + scaled_pixels.toString(), 'text', false, (data) => prediction = data)
    let p = prediction.split(" ").slice(0, 10)
    res = findBest2(p)
  //}
  //if(strokes.length == 0) res = {"max1": "--", "maxIdx1": "--", "max2": "--", "maxIdx2": "--"}
  strokeWeight(1)
  stroke(50,200,100)
  fill(50,200,100)
  textSize(20)
  text("Best guess: " + res.maxIdx1, 10, 40)
  textSize(15)
  text("Conf.: " + res.max1, 10, 60)
  textSize(20)
}

function findBest2(pred){
  let p = float(pred)
  let max1 = 0
  let maxIdx1 = 0
  let max2 = 0
  let maxIdx2 = 0
  for(let i = 0; i < p.length; i++){
    if(max1 < p[i]){
      max1 = p[i]
      maxIdx1 = i
    }
    if(max2 < p[i] && max1 > p[i]){
      max2 = p[i]
      maxIdx2 = i
    }
  }
  return {"max1": max1, "maxIdx1": maxIdx1, "max2": max2, "maxIdx2": maxIdx2}
}

function pixels2BinaryColor(pix, col){
  let new_pixels = []
  for(let i = 0; i < pix.length; i += 4){
    if (pix[i] == col){
      new_pixels[i] = 0
      new_pixels[i + 1] = 0
      new_pixels[i + 2]  = 0
      new_pixels[i + 3]  = 255
    }else{
      new_pixels[i] =  255
      new_pixels[i + 1] = 255
      new_pixels[i + 2] = 255
      new_pixels[i + 3] = 255
    }
  }
  return new_pixels
}

function pixels2BW_arr(pix, norm = false){
  let new_pixels = []
  let idx = 0
  let p = 0
    for(let c of pix){
      if (idx < 3) p += c / 3
      else p *= 255 / c
      idx++
      idx = idx % 4
      if (idx == 0){
        if(norm) p /= 255
        new_pixels.push(p)
        p = 0
      }
    }
  return new_pixels
}

function mousePressed(){
  if(mouseX < width && mouseX > 0 && mouseY > 0 && mouseY < height){
    strokes.push(new StrokeDrawer())
    paint = true
  }
}

function mouseReleased(){
  paint = false
}
