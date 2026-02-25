SELECT t1.customer_id ,count(*)as count_no_trans
from(
SELECT v.customer_id,t.transaction_id 
FROM Visits AS v
LEFT JOIN Transactions AS t
ON v.visit_id = t.visit_id
)as t1
WHERE t1.transaction_id is NULL
group by t1.customer_id
