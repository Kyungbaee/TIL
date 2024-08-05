from collections import defaultdict
def solution(genres, plays):
    best_genres, music_dict, answer_list = defaultdict(int), defaultdict(list), []
    
    for idx, g in enumerate(genres): 
        best_genres[g] += plays[idx]
        music_dict[g].append((idx, plays[idx]))
    best_genres = sorted(best_genres.items(), key=lambda x: x[1], reverse=True)

    for best in best_genres:
        best_music = sorted(music_dict[best[0]], key=lambda x:x[1], reverse=True)
        answer_list += list(map(lambda x: x[0], best_music[:2]))
    return answer_list
        
    
    