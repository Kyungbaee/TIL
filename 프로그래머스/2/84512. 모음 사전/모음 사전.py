def solution(word):
    word_list = []
    for one in ["A","E","I","O","U"]:
        word_list.append(one)
        for two in ["A","E","I","O","U"]:
            word_list.append(one+two)
            for thr in ["A","E","I","O","U"]:
                word_list.append(one+two+thr)
                for four in ["A","E","I","O","U"]:
                    word_list.append(one+two+thr+four)
                    for five in ["A","E","I","O","U"]:
                        word_list.append(one+two+thr+four+five)
    return word_list.index(word)+1