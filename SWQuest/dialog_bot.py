from flask import Flask, make_response, request, jsonify
from webcrawling import store_return, make_url
import random

app = Flask(__name__)

@app.route('/')
def index():
    return 'Hellow World!'

@app.route('/webhook', methods =['GET','POST'])
def webhook():
    req = request.get_json(force=True)
    command = req.get('queryResult').get('intent').get("displayName")
    print(command)
    if command == 'random':
        return make_response(jsonify(randoms()))
    else:
        return make_response(jsonify(results()))

def randoms():
    food_list = ['한식','일식','양식','중식','분식','세계음식','뷔페','카페','술집', '디저트']
    food = random.choice(food_list)

    if food == '한식':
        img_url = 'https://i.ibb.co/HGPXqkG/tile.jpg'
    elif food == '일식':
        img_url = "https://i.ibb.co/W5K2zs5/tile.jpg"
    elif food == '양식':
        img_url = "https://i.ibb.co/167m1Hk/tile.jpg"
    elif food == '중식':
        img_url = "https://i.ibb.co/B4CNX7L/tile.jpg"
    elif food == '분식':
        img_url = "https://i.ibb.co/W08rWBr/tile.jpg"
    elif food == '세계음식':
        img_url = "https://i.ibb.co/ZMfv5Mz/tile.jpg"
    elif food == '뷔페':
        img_url = "https://i.ibb.co/HpjCh6q/tile.jpg"
    elif food == '카페':
        img_url = "https://i.ibb.co/Vwr4pWt/tile.jpg"
    elif food == '술집':
        img_url = "https://i.ibb.co/s1XP50j/tile.jpg"
    else: #디저트
        img_url = "https://i.ibb.co/wsnTt0F/tile.jpg"

    response = \
        {
            'fulfillmentMessages': [
                {
                    "text": {
                        "text": ["{}은(는) 어때요?".format(food)]
                    },
                    "platform": "LINE"
                }
                , {
                    "image": {
                        "imageUri": img_url
                    },
                    "platform": "LINE"
                }
            ]
        }
    return response

def results():
    req = request.get_json(force=True)
    #print(req)
    #print('-----------------------------------------')
    parameters = req.get('queryResult').get('outputContexts')[0].get("parameters")
    place = parameters.get("address")
    category = parameters.get("cate")
    print(place, category)
    store_list = store_return(place,category)
    if not store_list:
        response = \
            {
                'fulfillmentMessages': [
                    {
                        "text": {
                            "text": [
                                "검색 결과가 없어요 ㅠㅠ"
                            ]
                        },
                        "platform": "LINE"
                    }
                ]
            }
    else:
        total_list = []
        for store in store_list:
            message = {
            "card": {
                "imageUri": store[0],
                "title": store[1],
                "subtitle": "평점 : {}점".format(store[2]),
                "buttons": [
                    {
                        "text": "링크",
                        "postback": store[3]
                    }
                ]
            },
            "platform": "LINE"
            }
            total_list.append(message)
        url = make_url(place, category)
        total_list.append({
                        "text": {
                            "text": [
                                "더 보고 싶으신가요?\n{}".format(url)
                            ]
                        },
                        "platform": "LINE"
        })

        response = \
        {
            'fulfillmentMessages': total_list
        }
    return response

#run the app
if __name__ == '__main__':
    app.run(port=6000)

