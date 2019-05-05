# Write your MySQL query statement below
SELECT T1.Day, ROUND(1.0 - (T2.Count / T1.Count), 2) AS 'Cancellation Rate'
FROM
(
    SELECT Day, COUNT(Day) AS Count
    FROM
    (
        SELECT Id, Status, Request_at AS Day
        FROM Trips
        WHERE Client_Id IN
        (
            SELECT Users_Id
            FROM Users
            WHERE Banned = 'No'
        ) AND Driver_Id IN
        (
            SELECT Users_Id
            FROM Users
            WHERE Banned = 'No'
        )
    ) AS T3
    WHERE Day >= '2013-10-01' AND Day <= "2013-10-03"
    GROUP BY Day
) AS T1,
(
    SELECT Day, COUNT(IF(Status = 'completed', Day, null)) AS Count
    FROM
    (
        SELECT Id, Status, Request_at AS Day
        FROM Trips
        WHERE Client_Id IN
        (
            SELECT Users_Id
            FROM Users
            WHERE Banned = 'No'
        ) AND Driver_Id IN
        (
            SELECT Users_Id
            FROM Users
            WHERE Banned = 'No'
        )
    ) AS T4
    WHERE Day >= '2013-10-01' AND Day <= "2013-10-03"
    GROUP BY Day
) AS T2
WHERE T1.Day = T2.Day