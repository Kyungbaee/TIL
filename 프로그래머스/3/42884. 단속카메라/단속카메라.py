'''
차량 리스트를 나가는 지점을 기준으로 정렬하고, 첫 번째 차량의 나가는 지점에 카메라를 설치한다고 가정합니다. 
그리고 다음 차량의 진입 지점이 현재 카메라 위치보다 앞서 있다면, 카메라를 추가로 설치해야 합니다. 

[[-20,-15], [-18,-13], [-14,-5], [-5,-3]]

첫 번째 카메라 : 첫 번째 차량의 진출 지점 -15
두 번째 카메라 : 세 번째 차량의 진출 지점 -5
'''

def solution(routes):
    routes = sorted(routes, key=lambda x: x[1])
    camera = [routes[0][1]]
    
    for i in range(1, len(routes)):
        if camera[-1] < routes[i][0]:
            camera.append(routes[i][1])
            
    return len(camera)