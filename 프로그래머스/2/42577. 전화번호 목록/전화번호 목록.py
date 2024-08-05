def solution(phone_book):
    phone_book = sorted(phone_book)
    for idx in range(len(phone_book)-1):
        if phone_book[idx] in phone_book[idx+1][:len(phone_book[idx])]: return False
    return True