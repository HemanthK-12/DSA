# Write your MySQL query statement below
SELECT A.id
FROM WEATHER AS A,WEATHER AS B
WHERE 
A.temperature>B.temperature 
AND 
A.recordDate=DATE_ADD(B.recordDate,INTERVAL 1 DAY); 