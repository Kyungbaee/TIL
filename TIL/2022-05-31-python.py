dt.date         # YYYY-MM-DD(문자)
dt.year         # 연(4자리숫자)
dt.month        # 월(숫자)
dt.month_name() # 월(문자)

dt.day          # 일(숫자)
dt.time         # HH:MM:SS(문자)
dt.hour         # 시(숫자)
dt.minute       # 분(숫자)
dt.second       # 초(숫자)
dt.quarter       # 분기(숫자)

dt.weekday_name  # 요일이름(문자) (=day_name())
dt.weekday       # 요일숫자(0-월, 1-화) (=dayofweek)
dt.weekofyear    # 연 기준 몇주째(숫자) (=week)
dt.dayofyear     # 연 기준 몇일째(숫자)
dt.days_in_month # 월 일수(숫자) (=daysinmonth)

dt.is_leap_year     # 윤년 여부
dt.is_month_start   # 월 시작일 여부
dt.is_month_end     # 월 마지막일 여부
dt.is_quarter_start # 분기 시작일 여부
dt.is_quarter_end   # 분기 마지막일 여부
dt.is_year_start    # 연 시작일 여부
dt.is_year_end	# 연 마지막일 여부  

- read_csv : csv파일 읽어오기
- .nunique : 유일값의 빈도수
- df.value_counts() : 요소 개수 세는 메서드
- df.isnull().sum() : 결측치 합
- df.dropna() : 결측치가 포함된 행 삭제
- df[ ] = pd.to_datetime(df[ ]) : 데이터 타입 변경
- df[ ].dt.month(or day, dayofweek, day_name) : 파생변수만들기(월, 일, 요일, 영문요일)
- \n : 줄바꿈
- df.map() : 여러 개의 데이터를 한 번에 다른 형태로 변환
- df.nlargest : 가장 큰 값 구하는 방법
- concat([dt, df]) : 데이터프레임 연결
- set( ) :  unique한 값


1. KOSIS 데이터 : 집계 데이터
    - 주제에 상관없이 대부분이 비슷한 형식을 가짐.
    - Raw data와 다른 분석 방식이 요구되나, 코시스 데이터들 간에는 분석 방법이 거의 비슷함
    - 집계 데이터를 불러와서 평균값을 낼 경우, 잘못된 해석으로 이어질 수 있음

        → sum을 쓰는 게 더 적합함

2. 데이터 타입 중에서도 32, 64 등 내가 정말 저만큼의 숫자가 필요한가 생각하면 메모리를 아낄 수도 있음 (?)
3. 기술통계를 보고, max값 등 분포가 눈에 튀는 부분이 있다 하면, 

    → 그 값을 가져다가 색인해서 보면 좋음


사실(Fact) : 의약품처방정보 데이터를 전처리하고 시각화하는 실습을 하였다.
느낌(Feeling): map과 dictionary를 실습해볼 수 있는 시간이었다.
교훈(Finding): 양이 많은 데이터에서 전처리는 후에 있을 과정 속도에 영향을 크게 미친다는 것을 느꼈다.
