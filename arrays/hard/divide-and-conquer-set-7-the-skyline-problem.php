<?php
/**
 * Created by PhpStorm.
 * User: GSU
 * Date: 13.04.2019
 * Time: 23:33
 */

/**
 * Given a set of rectangles represented by a height and an interval along the y-axis, determine the size of its union.
 */

/**
 * [height, y-start, y-end]
 */
$arInput = array(
    [8, 21, 31],
    [16, 12, 24],
    [9, 7, 12],
    [6, 0, 5]
);

/**
 * @param $arInput
 * @return int
 */
function getMaxHeight($arInput)
{
    return getMax($arInput, 0);
}

/**
 * @param $arInput
 * @return int
 */
function getMaxY($arInput)
{
    return getMax($arInput, 2);
}

/**
 * @param $arInput
 * @param $intIndex
 * @return int
 */
function getMax($arInput, $intIndex)
{
    $intMax = 0;
    foreach ($arInput as $arRect) {
        if ($intMax < $arRect[$intIndex]) {
            $intMax = $arRect[$intIndex];
        }
    }
    return $intMax;
}

/**
 * @param $arInput
 * @return array
 */
function getCoords($arInput)
{
    $arInputCoords = [];
    foreach ($arInput as $arRect) {
        $arInputCoords[] = [0, $arInput[0], $arInput[1], $arInput[2]];
    }
    return $arInputCoords;
}

$intMaxHeight = getMaxHeight($arInput);
$intMaxY = getMaxY($arInput);

/**
 * [x-start, x-end, y-start, y-end]
 */
$arInputCoords = getCoords($arInput);

/**
 * Way 1
 */

/**
 * Go through each value of h, on each line, calculate the sum of the lengths of the segments.
 * Find the sum of the lengths of the segments
 */

$intRectsUnionSize = 0;
for ($ih = 1; $ih <= $intMaxHeight; $ih++) {
    $arLine = [];
    $arLineStart = [];
    $arLineEnd = [];
    $arLineSorted = [];
    foreach ($arInput as $arRect) {
        if ($ih <= $arRect[0]) {
            $arLine[$arRect[1]][$arRect[2]] = [$arRect[1], $arRect[2]];
            $arLineStart[] = $arRect[1];
            $arLineEnd[$arRect[1]][] = $arRect[2];
        }
    }

    sort($arLineStart);
    $arLineStart = array_unique($arLineStart);

    foreach ($arLineEnd as $intLineStart => &$arInterval) {
        sort($arInterval);
    }

    foreach($arLineStart as $intLineStart) {
        foreach ($arLineEnd[$intLineStart] as $intLineEnd) {
            $arLineSorted[] = [$intLineStart, $intLineEnd];
        }
    }

    $intLineWeight = 0;
    $intLineSortedLength = count($arLineSorted);
    foreach ($arLineSorted as $index => $intInterval) {
        if($index + 1 < $intLineSortedLength) {
            if($intInterval[1] <= $arLineSorted[$index + 1][0]) {
                $intLineWeight += ($intInterval[0] + $intInterval[1]);
            } else {
                $intLineWeight += ($intInterval[0] + $arLineSorted[$index + 1][1]);
            }
        }
    }

    $intRectsUnionSize += $intLineWeight;

}

echo $intRectsUnionSize;
echo "\n";


/**
 * Way 2
 */

