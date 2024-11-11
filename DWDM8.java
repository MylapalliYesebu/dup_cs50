public class DWDM8 {

    static void distinctValues(int[] arr) {
        // Outer loop iterates over each element
        for (int i = 0; i < arr.length; i++) {
            // Inner loop checks if the current element is a duplicate
            boolean isDuplicate = false;
            for (int j = 0; j < i; j++) {
                if (arr[i] == arr[j]) {
                    isDuplicate = true;
                    break;
                }
            }

            // If not a duplicate, print it
            if (!isDuplicate) {
                System.out.print(arr[i] + " ");
            }
        }
    }

    public static void main(String[] args) {
        int[] arr = {1, 55, 67, 99, 11, 54, 55, 88, 99, 1, 13, 45};
        System.out.println("The Distinct Elements in array are: ");
        distinctValues(arr);
    }
}