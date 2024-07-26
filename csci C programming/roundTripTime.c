#include <stdio.h>
#include <stdlib.h>
#include <libsocket/libinetsocket.h>
#include <unistd.h>
#include <sys/time.h>
#include <string.h>

//function to calc time in ms
double time_ms(struct timeval start, struct timeval end)
{
    return (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_usec - start.tv_usec) / 1000.0;
}

int main()
{
    //SYDNEY
    int fd = create_inet_stream_socket("sydney.cs.sierracollege.edu", "5055", LIBSOCKET_IPv4, 0);
    if (fd < 0)
    {
        printf("Can't create socket\n");
        exit(1);
    } 
    /*/ FREMONT
    int fd = create_inet_stream_socket("fremont.cs.sierracollege.edu", "5055", LIBSOCKET_IPv4, 0);
    if (fd < 0)
    {
        printf("Can't create socket\n");
        exit(1);
    }  */
    printf("Connected\n");

    FILE *s = fdopen(fd, "r+");
    

    double rtt1, rtt2, rtt3; //variables to hold rtt values
    double sum_rtt = 0; //sum of rtt for avg
    struct timeval start_time, end_time;
    char line[100];

    for (int i = 1; i <= 3; i++) {
        gettimeofday(&start_time, NULL); //current time before sending data

        fprintf(s, "DATA PAYLOOOOOAD!\n"); //send data to server

        //response from server
        if (fgets(line, sizeof(line), s) == NULL)
        {
            printf("Failed to read");
            fclose(s);
            exit(1);
        }

        gettimeofday(&end_time, NULL); //current time after receiving response

        //calc rtt in milisecond
        double rtt = time_ms(start_time, end_time);
        printf("Round-trip %d: %.2f ms\n", i, rtt);

        sum_rtt += rtt; //current rtt to sum for avg

        sleep(1); //test for incorrectly low rtt 2 & 3
}

double avgRTT = sum_rtt / 3; //calculate average rtt
printf("Average Round-Trip time: %.2f ms\n", avgRTT);

fclose(s);
return 0;
}
/*
int main()
{
    
    
    //convert to FILE *
    FILE *s = fdopen(fd, "r+");

    //send HELO 
    fprintf(s, "HELO\n");

    //receive response
    char line[100];
    fgets(line, 100, s);
    printf("%s", line);

    //send DATE

    fprintf(s, "DATE\n");

    //reieve display respnose
    fgets(line, 100, s);
    printf("%s", line);

    //close connection
    fclose(s);
    close(fd);
} */