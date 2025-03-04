var ListNode = /** @class */ (function () {
    function ListNode(val, next) {
        this.val = (val === undefined ? 0 : val);
        this.next = (next === undefined ? null : next);
    }
    return ListNode;
}());
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */
function addToLL(listTail, value) {
    var newTail = new ListNode(value);
    listTail.next = newTail;
}
function mergeListsBounded(lists, low, high) {
    // Base Case
    if (high - low == 1) {
        return lists[low];
    }
    if (high - low == 0) {
        return null;
    }
    // Fetches two sorted linked lists
    var cut = Math.floor((high - low) / 2);
    var listOne = mergeListsBounded(lists, low, low + cut);
    var listTwo = mergeListsBounded(lists, low + cut, high);
    // Initializes the larger sorted LL
    var currentOne = listOne;
    var currentTwo = listTwo;
    var returnLLHead;
    var returnLLTail;
    if (!currentOne) {
        return currentTwo;
    }
    if (currentOne.val < currentTwo.val) {
        returnLLHead = currentOne;
        returnLLTail = currentOne;
        currentOne = currentOne.next;
    }
    else {
        returnLLHead = currentTwo;
        returnLLTail = currentTwo;
        currentTwo = currentTwo.next;
    }
    // Compare and merge two LLs
    while (currentOne && currentTwo) {
        // Add value from List One
        if (currentOne.val < currentTwo.val) {
            addToLL(returnLLTail, currentOne.val);
            returnLLTail = returnLLTail.next;
            currentOne = currentOne.next;
            // Add value from List Two
        }
        else {
            addToLL(returnLLTail, currentTwo.val);
            returnLLTail = returnLLTail.next;
            currentTwo = currentTwo.next;
        }
    }
    // Fill LL with remaining values
    while (currentOne) {
        addToLL(returnLLTail, currentOne.val);
        returnLLTail = returnLLTail.next;
        currentOne = currentOne.next;
    }
    while (currentTwo) {
        addToLL(returnLLTail, currentTwo.val);
        returnLLTail = returnLLTail.next;
        currentTwo = currentTwo.next;
    }
    return returnLLHead;
}
function mergeKLists(lists) {
    return mergeListsBounded(lists, 0, lists.length);
}
;
function main(LLArray) {
    var ListNodeMatrix = [];
    for (var i = 0; i < LLArray.length; i++) {
        var LLHead = new ListNode(LLArray[i][0]);
        var LLTail = LLHead;
        var innerListLength = LLArray[i].length;
        for (var j = 1; j < innerListLength; j++) {
            var newNode = new ListNode(LLArray[i][j]);
            LLTail.next = newNode;
            LLTail = newNode;
        }
        ListNodeMatrix.push(LLHead);
    }
    console.log(mergeKLists(ListNodeMatrix));
}
main([[-2, -1, -1, -1], []]);
// main([[1,4,5],[1,3,4],[2,6]])
