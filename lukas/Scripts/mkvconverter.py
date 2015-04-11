#!/usr/bin/env python3
import sys
import os
import json
import subprocess

def getJSONInfo(path):
    p = subprocess.check_output(['/usr/bin/ffprobe', '-show_format', '-show_streams', '-v', 'quiet', '-of', 'json', path])
    q = json.loads(p.decode("utf-8"))
    return(len(q['streams']))

def printUsage():
    print('Usage: mkvconverter.py INPUTFOLDER OUTPUTFOLDER ENG_TRACK GER_TRACK')
    print('ENG_TRACK and GER_TRACK are numbers, mostly 1 and 2. If it doesn\'t exist, use 0')
    print('Default Values are ger=1 eng=2')

def convert(inputFile, outputFile, ger, eng):
    if ger == None:
        convertSingleTrack(inputFile, outputFile, 1)
        return
    elif eng == None:
        convertSingleTrack(inputFile, outputFile, 2)
        return

    print(inputFile, outputFile, ger, eng)


    subprocess.call(["/usr/bin/mkvmerge", "-o", str(outputFile),
    "--forced-track", "0:no",
    "--language", eng+":eng", "--forced-track", eng+":no",
    "--language", ger+":ger", "--forced-track", ger+":no",
    "-a", "1,2", "-d", "0", "-S", "-T",
    "--no-global-tags", "--no-chapters", str(inputFile),
    "--track-order", "0:0,0:"+eng+",0:"+ger,])

def convertSingleTrack(inputFile, outputFile, track):
    if track == 1:
        track_lang = 'eng'
    else:
        track_lang = 'ger'



def main():

    if len(sys.argv) <= 2:
        printUsage()
        return

    #print('Number of arguments:', len(sys.argv), 'arguments.')
    #print ('Argument List:', str(sys.argv))
    mypath = os.path.abspath(sys.argv[1])
    myToPath = os.path.abspath(sys.argv[2])
    try:
        track_eng = sys.argv[3]
    except:
        track_eng = 1

    try:
        track_ger = sys.argv[4]
    except:
        track_ger = 2

#    print(mypath)

    # get only files in the folder mypath
    onlyfiles = [ f for f in os.listdir(mypath) if os.path.isfile(os.path.join(mypath,f)) ]

#    print(onlyfiles)

#    print(mypath, myToPath, track_ger, track_eng)


    for v in onlyfiles:
#        print(os.path.abspath(v), os.path.basename(v))

        convert(os.path.join(mypath, v), os.path.join(myToPath,os.path.splitext(v)[0]+".mkv"), track_ger, track_eng)

#        getJSONInfo(myToPath+os.path.splitext(v)[0]+".mkv")
#        call(["echo", mypath+os.path.splitext(v)[0]])
#        if len(sys.argv) > 2:
#           call(["/usr/bin/mkvmerge", "-o", myToPath+os.path.splitext(v)[0]+".mkv", "--forced-track", "0:no", "--language", "1:eng", "--forced-track", "1:no", "-a", "1", "-d", "0", "-S", "-T", "--no-global-tags", "--no-chapters", "(", mypath+v, ")", "--track-order", "0:0,0:1"])
#        else:
#            call(["/usr/bin/mkvmerge", "-o", mypath+os.path.splitext(v)[0]+".mkv", "--forced-track", "0:no", "--language", "1:eng", "--forced-track", "1:no", "-a", "1", "-d", "0", "-S", "-T", "--no-global-tags", "--no-chapters", "(", mypath+v, ")", "--track-order", "0:0,0:1"])

if __name__ == "__main__":
    main()
