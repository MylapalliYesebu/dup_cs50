import java.util.*;

class KmeansJ {

    public static void main(String[] args) {
        int dataset[][] = {
                {2, 1},
                {5, 2},
                {2, 2},
                {4, 1},
                {4, 3},
                {7, 5},
                {3, 6},
                {5, 7},
                {1, 4},
                {4, 1}
        };

        int k = 2;
        int part1[][] = new int[10][2];
        int part2[][] = new int[10][2];
        float mean1[][] = new float[1][2];
        float mean2[][] = new float[1][2];
        float temp1[][] = new float[1][2];
        float temp2[][] = new float[1][2];
        int sum11 = 0, sum12 = 0, sum21 = 0, sum22 = 0;
        double dist1, dist2;
        int i1 = 0, i2 = 0, itr = 0;

        // Printing the dataset
        System.out.println("Dataset: ");
        for (int i = 0; i < 10; i++) {
            System.out.println(dataset[i][0] + " " + dataset[i][1]);
        }

        System.out.println("\nNumber of partitions: " + k);

        // Assuming (2,2) and (5,7) are random means
        mean1[0][0] = 2;
        mean1[0][1] = 2;
        mean2[0][0] = 5;
        mean2[0][1] = 7;

        // Loop till the new mean and previous mean are the same
        while (!Arrays.deepEquals(mean1, temp1) || !Arrays.deepEquals(mean2, temp2)) {

            // Emptying the partitions
            for (int i = 0; i < 10; i++) {
                part1[i][0] = 0;
                part1[i][1] = 0;
                part2[i][0] = 0;
                part2[i][1] = 0;
            }
            i1 = 0;
            i2 = 0;

            // Finding distance and assigning points to clusters
            for (int i = 0; i < 10; i++) {
                dist1 = Math.sqrt(Math.pow(dataset[i][0] - mean1[0][0], 2) + Math.pow(dataset[i][1] - mean1[0][1], 2));
                dist2 = Math.sqrt(Math.pow(dataset[i][0] - mean2[0][0], 2) + Math.pow(dataset[i][1] - mean2[0][1], 2));

                if (dist1 < dist2) {
                    part1[i1][0] = dataset[i][0];
                    part1[i1][1] = dataset[i][1];
                    i1++;
                } else {
                    part2[i2][0] = dataset[i][0];
                    part2[i2][1] = dataset[i][1];
                    i2++;
                }
            }

            // Storing the previous mean
            temp1[0][0] = mean1[0][0];
            temp1[0][1] = mean1[0][1];
            temp2[0][0] = mean2[0][0];
            temp2[0][1] = mean2[0][1];

            // Finding new means
            sum11 = 0;
            sum12 = 0;
            sum21 = 0;
            sum22 = 0;

            for (int i = 0; i < i1; i++) {
                sum11 += part1[i][0];
                sum12 += part1[i][1];
            }

            for (int i = 0; i < i2; i++) {
                sum21 += part2[i][0];
                sum22 += part2[i][1];
            }

            mean1[0][0] = (float) sum11 / i1;
            mean1[0][1] = (float) sum12 / i1;
            mean2[0][0] = (float) sum21 / i2;
            mean2[0][1] = (float) sum22 / i2;

            itr++;
        }

        // Printing final partitions and means
        System.out.println("\nFinal Partition:");
        System.out.println("Part1:");
        for (int i = 0; i < i1; i++) {
            System.out.println(part1[i][0] + " " + part1[i][1]);
        }

        System.out.println("\nPart2:");
        for (int i = 0; i < i2; i++) {
            System.out.println(part2[i][0] + " " + part2[i][1]);
        }

        System.out.println("\nFinal Mean:");
        System.out.println("Mean1: " + mean1[0][0] + " " + mean1[0][1]);
        System.out.println("Mean2: " + mean2[0][0] + " " + mean2[0][1]);

        System.out.println("\nTotal Iterations: " + itr);
    }
}
