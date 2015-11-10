#include <stdio.h>
#define FRIENDSIZE 20

size_t findBestFriend(int friendcontact[], size_t size);

int main(void){

	size_t bestFriend = 0;
	int friendNum = 0;
	int friendcontact[FRIENDSIZE] = { 0, 1, 2, 3, 4, 5, 6, 7, 15, 0, 1 };


	bestFriend = findBestFriend(friendcontact, FRIENDSIZE);
	printf("%d\n", bestFriend);

}

size_t findBestFriend(int friendcontact[], size_t size){

	size_t friendNum = 0;
	size_t bestFriend = 0;
	for (friendNum = 0; friendNum < size; friendNum++) {

		if (friendcontact[friendNum] > bestFriend)
			return friendNum;
	}
}