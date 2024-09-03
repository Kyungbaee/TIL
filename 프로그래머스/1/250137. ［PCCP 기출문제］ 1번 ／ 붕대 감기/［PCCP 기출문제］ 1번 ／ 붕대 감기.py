def solution(bandage, health, attacks):
    hp, seq, time = health, 0, 0
    
    for atk in attacks:
        atk_time, damage = atk
        seq = atk_time-time-1
        time = atk_time
        hp = min(health, hp+(bandage[1]*seq)+bandage[2]*(seq//bandage[0]))
        seq = seq % bandage[0]
        
        hp -= damage
        if hp <= 0: return -1
    
    return hp