- 판다스에서 duplcate, set_index ,sort_index는 다시 변수에 할당 해야 각 기능이 적용된 데이터 프레임으로 사용 가능하다

- 날짜 데이터 -> datetime64로 변경하기는 방법 : df["확진일"] = pd.to_datetime(df["확진일"])

-Series 접근자(accessor) str->string, dt-> datetime, Categorical->cat,Sparse->sparse (시리즈에서만 사용가능) -> 데이터 프레임은 컬럼마다 데이터 타입이 다르기 때문에
ex) df["확진일"].dt.month 이런 식으로 datetime에서 month만 가지고 올 수 있다.

- 보통 날짜 데이터가 있으면 패생 변수를 이용해서  연,월,일을  나눈다

- astype(str)로 데이터 타입을 str로 변경 가능 ex) df["연도"].astype(str)

-map을 사용해서 요일 컬럼을 요일명으로 변환하고 "요일명"이라는 새로운 컬럼에 저장하기
   df["요일명"] = df["요일"].map(find_dayofweek) -> map에 적용할 find_dayofweek함수 작성
   map은 시리즈
   apply 시리즈,데이터프레임
   applymap 데이터프레임

-df["연도"].value_counts(normalize=True)
 normalize= True로 하면 counts value값이 합쳤을 때 1이 되도록 해준다.

-.loc[행]
 .loc[행, 열]
 .loc[조건, 열]
 
 - 중복확인 df[df.duplicated()]
 중복제거 df.drop_duplicates()

- 기술통계 df.describe()→수치형 데이터
                   df.describe(include="object") → 문자 데이터

- 연도 파생변수 만들기 
pd.to_datetime 을 통해 데이터 타입을 변경한 뒤 dt 접근자 로 접근
df["연도"] = df[”확진일”].dt.year
월(month), 일(day), 요일(dayofweek)

- df[”연도”].astype(str) 을 통해 수치 데이터를 문자 데이터로 변환

- datetime의 요일 숫자를 넘겨주면 요일명을 반환하여 요일명 컬럼에 저장
  def find_dayofweek(day_no):
  dayofweek = "월화수목금토일"
  return dayofweek[day_no]
  df["요일명"] = df["요일"].map(find_dayofweek)

- map/apply/applymap

- Series Accessor  ?
  dt / str / cat / sparse 
  str → 파이썬의 스트링 함수를 시리즈에서 사용, object 타입에서만 사용가능

- df["연도"].value_counts(normalize=True) * 100
  normalize 옵션

- pd.date_range

- %timeit

- to_frame() 
  시리즈 값을 데이터프레임으로 만들면 인덱스가 시리즈 값으로 부여

- pd.crosstab

- style.background_gradient()
  gu_m.style.background_gradient(cmap="Oranges_r") → _r은 색 반전
  해당되는 컬럼에서 가장 진한 색 표시

- 전체적인 빈도 확인할때는 씨본의 히트맵

- ~ 앞에 붙이면 false를 의미

- df.loc[조건,열] = “조건에 해당하는 열에 할당할 값

- loc 는 파생변수만들 때 많이 사용

-불리언 인덱싱
