#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <limits.h>
#include <curl/curl.h>

#define OPT(x) _Pragma (#x)


int main(void){
  CURL *curl;
  CURLcode res;

  curl = curl_easy_init();

  if(curl == NULL)
    return 0;

  curl_easy_setopt(curl, CURLOPT_URL, "https://example.com/getAccessAttributes?id=1");

  res = curl_easy_perform(curl);

  if(res != CURLE_OK) {
    fprintf(stderr, "Error: %s\n", curl_easy_strerror(res));
    return 0;
  }

  curl_easy_cleanup(curl);
}
