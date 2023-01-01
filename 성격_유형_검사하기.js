const survey = ["AN", "CF", "MJ", "RT", "NA"];
const choices = [5, 3, 2, 7, 5];
function solution(survey, choices) {
  var answer = "";
  const surveyResult = {};
  const indicator = ["RT", "CF", "JM", "AN"];

  for (let i = 0; i < indicator.length; i++) {
    surveyResult[indicator[i][0]] = 0;
    surveyResult[indicator[i][1]] = 0;
  }

  for (let i = 0; i < survey.length; i++) {
    const target = survey[i];
    if (choices[i] > 4) {
      surveyResult[target[1]] += choices[i] - 4;
      continue;
    }
    if (choices[i] < 4) {
      surveyResult[target[0]] += 4 - choices[i];
    }
  }
  for (let elem of indicator) {
    if (surveyResult[elem[0]] >= surveyResult[elem[1]]) {
      answer += elem[0];
      continue;
    }
    if (surveyResult[elem[0]] < surveyResult[elem[1]]) {
      answer += elem[1];
      continue;
    }
  }

  return answer;
}
