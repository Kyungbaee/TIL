def solution(bridge_length, weight, truck_weights):
    bridge, finish = [], []
    time, pop = 0, 0
    
    while(len(finish) < len(truck_weights)):
        ## 다리 위의 트럭 MOVE
        bridge = list(map(lambda x: (x[0], x[1]+1),bridge))
        ## 다리를 지난 트럭 OUT
        if (bridge) and (bridge[0][1]==bridge_length):
            finish.append(bridge[0])
            del bridge[0]
        ## 다리 위에 트럭 ADD
        if pop < len(truck_weights):
            sum_weight = sum([bridge[i][0] for i in range(len(bridge))]) + truck_weights[pop]
            if len(bridge)<bridge_length and sum_weight<=weight:
                bridge.append((truck_weights[pop],0))
                pop += 1
        time += 1
    return time
