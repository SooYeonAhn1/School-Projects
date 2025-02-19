from email.mime import image
from email.policy import default
from fileinput import filename
from operator import methodcaller
from random import sample
from urllib import request
from flask import Flask, render_template, url_for, request, session, flash, redirect, Response
from flask_sqlalchemy import SQLAlchemy
from datetime import timedelta, datetime
#from sqlalchemy_imageattach.entity import Image, image_attachment
from werkzeug.utils import secure_filename
import os


app = Flask(__name__)
app.secret_key = 'SECRETTTTTTT'
app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///tempor.db'
app.config['SQLALCHEMY_TRACK_MODIFICATIONS'] = False
UPLOAD_FOLDER = '/images2'
app.config['UPLOAD_FOLDER'] = UPLOAD_FOLDER
app.permenant_session_lifetime = timedelta(minutes=10)
db = SQLAlchemy(app)

class Handwriting(db.Model):
    id = db.Column(db.Integer,primary_key=True)
    content = db.Column(db.String(500), nullable=False)
    img = db.Column(db.Text)
    name = db.Column(db.Text, default='nothing')
    mimetype = db.Column(db.Text)
    date_created = db.Column(db.DateTime, default=datetime.utcnow)
    def __repr__(self):
        return '<Handwriting %r>' % self.id
    

@app.route('/', methods=['POST', 'GET'])
def index():
    if request.method == 'POST':
        imagine = request.files["image_input"]
        filename = secure_filename(imagine.filename)
        mimetype = imagine.mimetype
        #imagine_pic = request.files["image_input"]
        #magine_pic.save(os.path.join(app.config['UPLOAD_FOLDER']), filename)
        if not filename or not mimetype:
            return 'Nope', 400
        #handwriting_return = request.form["image_input"]
        Analyzed_sample = Handwriting(content=filename,mimetype=mimetype, img = imagine.read())
        flash('Analysis being implemented please wait')
        #flash(handwriting_return)
        
        try:
            db.session.add(Analyzed_sample)
            db.session.commit()
            return redirect('/')
        except:
            return 'issue'
        
    
    else:
        if "image_input" in session:
            handwriting_return = session["image_input"]
        handwrites = Handwriting.query.order_by(Handwriting.id).all()
        return render_template('index.html', samples = handwrites)
@app.route('/delete/<int:id>')
def delete(id):
    delete_this = Handwriting.query.get_or_404(id)
    
    try:
        db.session.delete(delete_this)
        db.session.commit()
        return redirect('/')
    except:
        return 'Not able to delete'

@app.route('/display/<int:id>')
def display(id):
    img = Handwriting.query.filter_by(id=id).first()
    if not img:
        return 'Not found', 404
    return Response(img.img, mimetype=img.mimetype)
if __name__ == "__main__":
    # db.create_all()
    app.run(debug=True)
    