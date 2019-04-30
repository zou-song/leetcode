# Write your MySQL query statement below
SELECT T1.Id
FROM Weather AS T1, Weather AS T2
WHERE DATE_SUB(T1.RecordDate, INTERVAL 1 DAY) = T2.RecordDate AND T1.Temperature > T2.Temperature