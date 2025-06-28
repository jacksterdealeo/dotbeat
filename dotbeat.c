#include<stdio.h>
#include<time.h>

int main(void) {
    const char* months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    time_t timer = time(NULL);
    struct tm* date = gmtime(&timer);

    date->tm_hour += 1;     // Add one hour
    timer = timegm(date);
    date = gmtime(&timer);
    
    double dotbeat;
    dotbeat = (date->tm_sec + (date->tm_min * 60) + (date->tm_hour * 3600));
    dotbeat = dotbeat / 86.4;

    printf("\033[91md\033[0m%d.", date->tm_mday);
    printf("%s ", months[date->tm_mon]);
    printf("\033[91m@\033[0m%.2f\n", dotbeat);
    return 0;
}
