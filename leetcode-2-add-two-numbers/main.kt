/**
 * Example:
 * var li = ListNode(5)
 * var v = li.`val`
 * Definition for singly-linked list.
 * class ListNode(var `val`: Int) {
 *     var next: ListNode? = null
 * }
 */
class Solution {
    fun sumAndCarry(l1: ListNode?, l2: ListNode?, carry: Int = 0): Pair<Int, Int> {
        val val1 = l1?.`val` ?: 0
        val val2 = l2?.`val` ?: 0
        return ((val1 + val2 + carry) % 10 to (val1 + val2 + carry) / 10)
    }
    
    fun addTwoNumbers(l1: ListNode?, l2: ListNode?): ListNode? {
        var _l1 = l1
        var _l2 = l2
        var result: ListNode? = null
        var iterator = ListNode(0)
        var carry = 0
        
        while (_l1 != null || _l2 != null || carry > 0) {
            sumAndCarry(_l1, _l2, carry).let { (sum, _carry) ->
                iterator.next = ListNode(sum)
                iterator = iterator.next!!
                carry = _carry
                _l1 = _l1?.next
                _l2 = _l2?.next
            }
            if (result == null) {
                result = iterator
            }
        }
        return result
    }
}