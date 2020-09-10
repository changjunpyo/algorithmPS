import re


def solution(m, musicinfos):
    answer = "(None)"
    playtime = 0
    for i in range(0, len(musicinfos)):
        musicinfo = musicinfos[i].split(",")
        time = 60 * (int(musicinfo[1][:2]) - int(musicinfo[0][:2]))
        time += (int(musicinfo[1][3:]) - int(musicinfo[0][3:]))
        count = 0
        for x in musicinfo[3]:
            if x != "#":
                count += 1
        music = musicinfo[3] * (time//count)
        rest_count = 0
        for x in range(len(musicinfo[3])):
            if musicinfo[3][x] != "#":
                rest_count += 1
            if time % count < rest_count:
                music += musicinfo[3][:x]
                break

        list = [(i.start(), i.end()) for i in re.finditer(m, music)]
        for x in list:
            if x[1] >= len(music) or music[x[1]] != "#":
                if playtime < time:
                    answer = musicinfo[2]
                    playtime = time
                    break

    return answer
