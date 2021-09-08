class Solution {
  fun twoSum(nums: IntArray, target: Int): IntArray {
    val map = HashMap<Int, Int>()
    nums.forEachIndexed { index, value ->
      if (map.contains(target - value)) {
        return arrayOf(map[target - value]!!, index).toIntArray()
      }
      if (!map.contains(value)) {
        map[value] = index   
      }
    }
    return arrayOf(-1, -1).toIntArray()
  }
}
