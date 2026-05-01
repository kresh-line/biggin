from collections import deque

graph = {}
graph["you"] = ["alice", "bob", "claire"]
graph["bob"] = ["anuj", "peggy"]
graph["alice"] = ["peggy"]
graph["claire"] = ["jonny", "jon"]
graph["anuj"] = ["jem","thef"]
graph["peggy"] = ["mag"]
graph["thef"] = []
graph["jonny"] = ["sdd","jon"]
graph["jon"] = ["anam"]
graph["mag"] = []
graph["jem"] = []
graph["sdd"] = []
graph["anam"] = []



def person_is_seller(name):
    return name[0] == 'j'

def search(name):
    search_queue = deque()
    search_queue += graph[name]
    searched = set()
    while search_queue:
        person = search_queue.popleft()
        if person not in searched:
            if person_is_seller(person):
                print(person + " is a mango seller!")
                return True
            else:
                search_queue += graph[person]
                searched.add(person)
    return False

search("you")
