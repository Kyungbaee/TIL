# 필요한 라이브러리 불러오기, josn 데이터 로드하기 때문에 json도 추가.
import pandas as pd
import plotly.express as px
import json

# geojson 데이터 열기
with open('지도데이터이름', encoding='UTF-8') as f:
    data = json.load(f)

# json 데이터 안에 features > properties > CTP_KOR_NM <- 요놈이 지역별 이름
# json 데이터 안에 features > properties > coordinates <- 요놈이 지역별 위도,경도
# json 데이터 안에 CTP_KOR_NM 값을 우리가 필요한 데이터 지역이름과 똑같게 맞춘다.
# 아래 FOR문 두개는 지역이름 확인할 때만 사용

for x in data['features']:
    x['id'] = x['properties']['CTP_KOR_NM'] 
    
for idx, _ in enumerate(data['features']):
    print(data['features'][idx]['id'])
    
# 기존의 지역별 데이터 이름을 CTP_KOR_NM과 같이 맞춰준다. KEY값으로 쓸 예정
mapper = [
    ('경기', '경기도'),
    ('서울', '서울특별시'),
    ('충북', '충청북도'),
    ('인천', '인천광역시'),
    ('충남', '충청남도'),
    ('광주', '광주광역시'),
    ('부산', '부산광역시'),
    ('강원', '강원도'),
    ('전남', '전라남도'),
    ('대구', '대구광역시'),
    ('전북', '전라북도'),
    ('울산', '울산광역시'),
    ('제주', '제주특별자치도'),
    ('경북', '경상북도'),
    ('세종', '세종특별자치시'),
    ('경남', '경상남도'),
    ('대전', '대전광역시'),
]
get_region = lambda gubun: [x[1] for x in mapper if x[0] == gubun][0]
데이터프레임이름['geo_region'] = 데이터프레임이름.발생지역별.apply(get_region)

# choropleth_mapbox로 시각화한다.
fig = px.choropleth_mapbox(
   데이터프레임이름, 
   geojson=data,                            # 위에서 load한 geojson 데이터 이름
   locations='geo_region',                  # CTP_KOR_NM과 맞춘 지역별 이름 컬럼
   color='2014 년',                         # 색으로 칠할 시리즈 데이터
   color_continuous_scale="Viridis",        # 색 조합
   featureidkey="properties.CTP_KOR_NM",    # featureidkey를 사용하여 id 값을 갖는 키값 지정
   mapbox_style="carto-positron",           # 지도 스타일
   zoom=5.5,
   center = {"lat": 35.757981, "lon": 127.661132},
   opacity=0.6,
   labels={'localocccnt'}
)
fig.update_geos(fitbounds="locations", visible=False)
fig.update_layout(margin={"r":0,"t":0,"l":0,"b":0})
fig.show()

![캡처](https://user-images.githubusercontent.com/105343823/170421847-b4be815d-af76-432d-9e65-3baa1a8251fc.PNG)
