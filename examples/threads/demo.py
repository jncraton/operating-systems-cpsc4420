import threading
import json
import time
from urllib.request import urlopen, Request

junk_foods = [
    "Pizza",
    "Popcorn",
    "Hamburger",
    "Pepsi",
    "Potato_chips",
    "Cake",
]

url = "https://en.wikipedia.org/w/api.php?action=parse&format=json&page="


def get_desc(food):
    url = f"https://en.wikipedia.org/w/api.php?action=parse&format=json&page={food}"
    headers = {"User-Agent": "jncraton-pthread-demo/1.0 (User:Jncraton)"}
    req = Request(url, headers=headers)
    contents = urlopen(req).read()
    print(f"{food}: {json.loads(contents)['parse']['properties'][0]['*']}")


t = time.time()

for food in junk_foods:
    get_desc(food)

print("Single threaded time:" + str(time.time() - t))

t = time.time()

threads = []

for food in junk_foods:
    thread = threading.Thread(target=get_desc, args=(food,))
    thread.start()
    threads.append(thread)

for thread in threads:
    thread.join()

print("Multi threaded time:" + str(time.time() - t))

exit()
