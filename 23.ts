class ListNode {
    val: number
    next: ListNode | null
    constructor(val?: number, next?: ListNode | null) {
        this.val = (val===undefined ? 0 : val)
        this.next = (next===undefined ? null : next)
    }
}

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

function addToLL(listTail: ListNode, value: number) {
  let newTail: ListNode = new ListNode(value)
  listTail.next = newTail;
}

function mergeListsBounded(lists: Array<ListNode | null>, low: number, high: number): ListNode {
  // Base Case
  if (high - low == 1) {
    return lists[low];
  }

  if (high - low == 0) {
    return null;
  }

  // Fetches two sorted linked lists
  let cut: number = Math.floor((high - low) / 2);
  let listOne: ListNode = mergeListsBounded(lists, low, low + cut);
  let listTwo: ListNode = mergeListsBounded(lists, low + cut, high);


  // Initializes the larger sorted LL
  let currentOne: ListNode = listOne;
  let currentTwo: ListNode = listTwo;
  let returnLLHead: ListNode;
  let returnLLTail: ListNode;

  if (!currentOne) {
    return currentTwo;
  }
  if (!currentTwo) {
    return currentOne;
  }
  if (currentOne.val < currentTwo.val) {
    returnLLHead = currentOne;
    returnLLTail = currentOne;
    currentOne = currentOne.next
  } else {
    returnLLHead = currentTwo;
    returnLLTail = currentTwo;
    currentTwo = currentTwo.next
  }

  // Compare and merge two LLs
  while (currentOne && currentTwo) {
    // Add value from List One
    if (currentOne.val < currentTwo.val) {
      addToLL(returnLLTail, currentOne.val)
      returnLLTail = returnLLTail.next;
      currentOne = currentOne.next
    // Add value from List Two
    } else {
      addToLL(returnLLTail, currentTwo.val)
      returnLLTail = returnLLTail.next;
      currentTwo = currentTwo.next
    }
  }

  // Fill LL with remaining values
  while (currentOne) {
    addToLL(returnLLTail, currentOne.val)
    returnLLTail = returnLLTail.next;
    currentOne = currentOne.next
  }
  while (currentTwo) {
    addToLL(returnLLTail, currentTwo.val)
    returnLLTail = returnLLTail.next;
    currentTwo = currentTwo.next
  }

  return returnLLHead
}

function mergeKLists(lists: Array<ListNode | null>): ListNode | null {
  return mergeListsBounded(lists, 0, lists.length)
};


function main(LLArray) {
  let ListNodeMatrix = []
  for (let i = 0; i < LLArray.length; i++) {
    let LLHead: ListNode = new ListNode(LLArray[i][0]);
    let LLTail: ListNode = LLHead;
  
    let innerListLength: number = LLArray[i].length
    for (let j = 1; j < innerListLength; j++) {
      let newNode: ListNode = new ListNode(LLArray[i][j])
      LLTail.next = newNode;
      LLTail = newNode;
    }

    ListNodeMatrix.push(LLHead);
  }
  
  
  console.log(mergeKLists(ListNodeMatrix))
}

main([[-2,-1,-1,-1],[]])
// main([[1,4,5],[1,3,4],[2,6]])