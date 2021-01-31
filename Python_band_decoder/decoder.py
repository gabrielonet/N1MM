import socket
localIP     = "127.0.0.1"
localPort   = 12060
bufferSize  = 1024
msgFromServer       = "Hello UDP Client"
bytesToSend         = str.encode(msgFromServer)
UDPServerSocket = socket.socket(family=socket.AF_INET, type=socket.SOCK_DGRAM)
UDPServerSocket.bind((localIP, localPort))
print("UDP server up and listening")
freq_temp = 0
while(True):
    bytesAddressPair = UDPServerSocket.recvfrom(bufferSize)
    message = bytesAddressPair[0]
    clientMsg = "Message from Client:{}".format(message)
    parser1 = clientMsg.split("</Freq")[0]
    freq = int(float(parser1.split("Freq>")[1]))
    if freq != freq_temp :
        freq_temp = freq
        #print freq
        if 100000 < freq < 300000:
            print "Banda de 160 metri , 1'st relay function"
        if 320000 < freq < 400000:
            print "Banda de 80 metri ,  2'nd relay function"
        if 500000 < freq < 800000:
            print "Banda de 40 metri , 3'rd relay function"
        if 1300000 < freq < 1500000:
            print "Banda de 20 metri , 4'th relay function"
        if 2000000 < freq < 2300000:
            print "Banda de 15 metri , 5'th relay function"            
        if 2700000 < freq < 3000000:
            print "Banda de 10 metri , 6'th relay function"      
    
