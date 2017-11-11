CHALLENGE_FILE = "/home/box/answer1.txt"
CHALLENGE_TEXT = "for(i=0; i<12; i++)"

def test_connection(s):
    assert s.run('true').succeeded, "Could not connect to server"

#def test_file_content(s):
#    file_content = s.run('cat /home/box/key.txt')
#    assert 'secret' in file_content, "Incorrect file content"
    
def test_file_exists(s):
    cmd = 'test -f ' + CHALLENGE_FILE
    assert s.run(cmd).succeeded, "File not found"

def test_file_content(s):
    file_content = s.run('cat ' + CHALLENGE_FILE)
    assert file_content == CHALLENGE_TEXT, "Answer in file does not equal to right answer"
