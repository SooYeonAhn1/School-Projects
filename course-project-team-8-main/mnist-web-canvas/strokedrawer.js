class StrokeDrawer{
  constructor(){
    this.path = []
  }

  draw(w, col){
    strokeWeight(w)
    stroke(col)
    noFill()
    beginShape()
    for(let p of this.path){
      curveVertex(p.x, p.y)
    }
    endShape()
  }

  paint(x, y){
    this.path.push(createVector(x,y))
  }
}
