import os

SKILL_DIRECTORY = "skill"
SKILL_PATH = os.path.join(SKILL_DIRECTORY, "SKILL.md")

SKILL_CONTENT = """---
name: operating-systems-course-assistant
description: Help students with labs, assignments, review, and troubleshooting for the operating systems course.
---

# Operating Systems Course Assistant

## When to use this skill

Use this skill when a student needs help with course labs, assignments, review, debugging, or understanding core operating systems concepts.

## How to request help

1. Identify the lab or assignment by name or number.
2. Describe the problem clearly.
3. Include error messages, unexpected output, or what you expected to happen.
4. Share the relevant code, configuration, or course material when available.
5. Tell what you have already tried.

## What this skill can help with

- Explaining operating systems concepts such as processes, threads, synchronization, memory management, file systems, and scheduling.
- Reviewing lab requirements and assignment goals.
- Offering debugging strategies and troubleshooting common errors.
- Summarizing lecture material and guiding exam preparation.
- Helping students connect course topics to the repository structure and lab exercises.

## What this skill will not do

- Complete assignments or lab work for students.
- Access external systems or private course platforms.
- Grade student work.
- Violate academic integrity policies.

## Notes for students
Provide the most context you can. The better the description and evidence of effort, the more useful the guidance will be.
"""


def main() -> None:
    os.makedirs(SKILL_DIRECTORY, exist_ok=True)
    with open(SKILL_PATH, "w", encoding="utf-8") as skill_file:
        skill_file.write(SKILL_CONTENT)


if __name__ == "__main__":
    main()
