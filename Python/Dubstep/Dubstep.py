def song_decoder(song):
    # WUBWUBWUBAWUBWUBWUBBWUBWUBWUBC

    newSong = song.replace("WUB", " ")

    for i in range(len(newSong)):
        newSong = newSong.replace("  ", " ")
    
    if newSong[0] == " ":
        newSong = newSong[1:]
    if newSong[len(newSong) - 1] == " ":
        newSong = newSong[:-1]

    print(newSong)
    return newSong


song_decoder("AWUBBWUBC")