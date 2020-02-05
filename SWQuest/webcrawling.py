import lxml
from bs4 import BeautifulSoup
import requests
from fake_useragent import UserAgent
from pprint import pprint

def make_url(place, category):
    if category == '전체':
        url = 'https://www.mangoplate.com/search/{}'.format(place)
    else:
        url = 'https://www.mangoplate.com/search/{}-{}'.format(place, category)
    return url

def store_return(place, category):
    ua = UserAgent()
    header = {'user-agent': ua.chrome}
    url = make_url(place, category)
    page = requests.get(url, headers=header)
    soup = BeautifulSoup(page.content, 'lxml')

    tags = soup.find_all('figure', class_='restaurant-item')
    place_list =[]
    num = 6 #보여줄 갯수
    if not tags:
        pass
    else:
        i = 1
        for tag in tags:
            if i > num:
                break
            # 이미지 긁어오기
            imag = tag.img['data-original'].split('?')[0]
            # 가게이름
            div_link = tag.find('div', class_='info')
            name = div_link.find('a').h2.text.replace('  ', '')
            name = name.replace('\n', '')
            # 가게평점
            grade = div_link.find('strong').text
            # 가게링크
            link = 'https://www.mangoplate.com/{}'.format(div_link.find('a')['href'])
            place_list.append([imag,name,grade,link])
            i+=1
    return place_list

if __name__ == "__main__":
    #테스트용
    stores = store_return('강남역','치킨')
    pprint(stores)

