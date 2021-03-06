from flask import Flask

app = Flask(__name__)

@app.route('/')
def index():
    return "Hello World!!"

@app.route('/user', methods = ['GET'])
def get_user():
    return "GET /user called!!"

@app.route('/user', methods = ['POST'])
def post_user():
    return "POST /user called!!"

@app.route('/user', methods = ['PUT'])
def put_user():
    return "PUT /user called!!"

@app.route('/user', methods = ['DELETE'])
def delete_user():
    return "DELETE /user called!!"

@app.route('/post')
def get_post():
    return "Hello Post!!"

@app.route('/user/list')
def get_user_list():
    return "Hello User List!!"

if __name__ == '__main__':
    app.run(debug=True, port = 6000)