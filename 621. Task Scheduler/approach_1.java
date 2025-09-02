class Solution {
    class Task {
        char label;
        int freq;

        Task(char label, int freq) {
            this.label = label;
            this.freq = freq;
        }
    }

    public int leastInterval(char[] tasks, int n) {
        Map<Character, Integer> taskFreq = new HashMap<>();
        for (char task : tasks) {
            taskFreq.put(task, taskFreq.getOrDefault(task, 0) + 1);
        }

        PriorityQueue<Task> maxHeap = new PriorityQueue<>(
            (a, b) -> Integer.compare(b.freq, a.freq)
        );

        for (var entry : taskFreq.entrySet()) {
            Task task = new Task(entry.getKey(), entry.getValue());
            maxHeap.offer(task);
        }

        Map<Task, Integer> pendingTime = new HashMap<>();
        
        int completed = 0, ans = 0;
        while (completed < tasks.length) {
            ++ans;

            if (!pendingTime.isEmpty()) {
                updatePendingTime(pendingTime, maxHeap);
            }

            if (maxHeap.isEmpty()) {
                continue;
            }

            ++completed;
            var task = maxHeap.poll();
            task.freq--;

            if (task.freq > 0) {
                pendingTime.put(task, n);
            }
        }
        
        return ans;
    }

    private void updatePendingTime(Map<Task, Integer> pendingTime, PriorityQueue<Task> maxHeap) {
        Iterator<Map.Entry<Task, Integer>> it = pendingTime.entrySet().iterator();
        while (it.hasNext()) {
            Map.Entry<Task, Integer> entry = it.next();
            Task task = entry.getKey();
            int newTime = entry.getValue() - 1;

            if (newTime < 0) {
                maxHeap.offer(task);
                it.remove();
            } else {
                entry.setValue(newTime);
            }
        }
    }
}

/*
    Time Complexity: O(n * m)
    Space Complexity: O(1)
*/
