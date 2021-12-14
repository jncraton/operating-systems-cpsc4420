from dateutil.rrule import rruleset, rrule, WEEKLY, MO, TU, WE, TH, FR
from datetime import datetime
import csv
import json

config = json.load(open('config.json'))

day_map = {"M": MO, "T": TU, "W": WE, "R": TH, "F": FR}
lecture_days = [day_map[d] for d in config["lecture_days"]]

rules = rruleset()
rules.rrule(
    rrule(
        WEEKLY,
        dtstart=datetime.fromisoformat(config["start_date"]),
        until=datetime.fromisoformat(config["end_date"]),
        byweekday=lecture_days,
    )
)
for b in config["breaks"]:
    rules.exdate(datetime.fromisoformat(b))

with open('topics.tsv') as f:
    for i, day in enumerate(zip(rules, csv.reader(f))):
        print(f"{i+1}. {day[0].strftime('%A, %B %d')}: {day[1][0]}")
