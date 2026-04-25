from collections import deque
def person_is_seller(name):
    return name[-1]=='m'
def search(name):
    search_queue=deque()
    search_queue+=graph[name]
    searched=set()
    while search_queue:
        person=search_queue.popleft()
        if not person in searched:
            if person_is_seller(person):

             print(person + "is a mango seller!")
             return True
        else:
             search_queue+=graph[person]
             searched.add(person)
    return False                
search("you")